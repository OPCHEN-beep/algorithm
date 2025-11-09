//并查集的实现

//初始化
const int N = 1e6 + 10;

int n;
int fa[N];  //双亲表示法所需数组
//初始化并查集 
void init()
{
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
} 
 
//查询操作
int find(int x)
{
	if(fa[x] == x) return x;
	return find(fa[x]);
	
	//一行实现
	return fa[x] == x ? x : find(fa[x]); 
} 

//合并操作
void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
 } 
 
 //判断操作
 bool issame(int x, int y)
 {
 	return find(x) == find(y);
  } 
  
//并查集的优化
//找根节点 - 路径压缩
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
	
	//一行实现
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
 } 
