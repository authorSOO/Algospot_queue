#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
int a[555][555];
int dis[555][555];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
			dis[i][j]=-1;
		}
	}
	queue<pair<int,int>> q;
	queue<pair<int,int>> next_queue;
	dis[0][0]=0;
	q.push(make_pair(0,0));

	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(dis[nx][ny]==-1){
					if(!a[nx][ny]){
						dis[nx][ny]=dis[x][y];
						q.push(make_pair(nx,ny));
					}
					else{
						dis[nx][ny]=dis[x][y]+1;
						next_queue.push(make_pair(nx,ny));
					}					
				}	
			}			
		}
		if(q.empty()){
			q=next_queue;
			next_queue = queue<pair<int,int>>();
		}
		
	}
	cout<<dis[n-1][m-1]<<endl;
	
	
	return 0;
}
