#include <bits/stdc++.h>
using namespace std;
#define For(a,sta,en) for(int a = sta;a <= en;a++)
inline int read(){
    int sum = 0,fu = 1;char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') fu = -1;ch = getchar();}
    while(isdigit(ch)) { sum = (sum<<1)+(sum<<3)+(ch^48);ch =getchar();} return sum * fu;
}
const int N = 1<<24;
int g[N],nxt[14][6],fa[N],ans[30],choice[N];
struct node{
    int state;   //状态
    double F;  //状态对应估价函数值
    node(int s):state(s){  //构造函数，冒号后面部分相当于 state = s;
        double h = 0;
        F = 0;
        For(i,0,11) if((s>>(i<<1))&3) h += 4 - ((s >> (i << 1)) & 3); //计算不处在状态1的旋钮的对应的h值
        F =  h / 2 + g[s];   //可以在h/2前乘一个玄学系数
    }
    bool operator<(const node &y) const{
        return F > y.F;  //估价函数值小的放前面
    }
};
priority_queue<node>q;

int main(){
    int button,Start = 0;
    For(i,0,11){
        button = read();                             //读入第i+1个旋钮状态
        Start |= (button - 1) << (i << 1);      //记录初始状态
        For(j,0,3) nxt[i][j] = read()-1;
    }
    q.push(node(Start));  //调用构造函数，顺便计算出估价函数值
    g[Start] = 0;
    while(!q.empty()){
        int state = q.top().state;
        q.pop();
        if(state == 0) break;
        int si,sNxt,nx,nextState;
        For(i,0,11){
            si = (state>>(i<<1))&3;
            nx = nxt[i][si];
            sNxt = (state>>(nx<<1))&3;
            nextState = state ^ (si << (i << 1)) ^ (((si + 1) & 3) << (i << 1)) ^ (sNxt << (nx << 1)) ^ (((sNxt + 1) & 3) << (nx << 1));
            //如果没有访问过就可以转移新状态了
            if(!g[nextState]){
                g[nextState] = g[state] + 1;
                fa[nextState] = state;      //用于回溯
                choice[nextState] = i + 1;
                q.push(node(nextState));
            }
        }
    }
    int cnt = 0,state = 0;
    while(state != Start){
        ans[++cnt] = choice[state];
        state = fa[state];
    }
    printf("%d\n",cnt);
    for(int i = cnt;i;i--) printf("%d ",ans[i]);
    return 0;
}
