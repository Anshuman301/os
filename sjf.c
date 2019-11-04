#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define not_exec 0
#define exec 1
struct process{
	int pid;
	int at;
	int bt;
	int wt,ft;
	int status;
};
typedef struct process process;

int sumBt(process *p,int n){
	int sum = 0;
	for(int i=0;i < n;i++){
		sum+=p[i].bt;
	}
	return sum;
}

int firstArrProcess(process *p,int n,int ct){
	int min=INT_MAX,pos=-1;
	for(int i=0; i< n;i++){
		if(p[i].status==not_exec && ct>=p[i].at && min >= p[i].bt){
			min=p[i].bt;
			pos=i;
		}
	}
	// printf("pos:-%d \n",pos);
	return pos;
}
void solve(process *p,int n){
	int ct=0,sum,spidx;
	sum = sumBt(p,n);
	/*Initial process are not executed*/
	for(int i=0;i  < n;i++){
		p[i].status=not_exec;
		p[i].wt=0;
		p[i].ft=0;
	}
	do{
		spidx = firstArrProcess(p,n,ct);
		if(spidx == -1){
			ct++;
			continue;
		}
		else{
			for(int i=0;i<n;i++){
			if(i!=spidx && p[i].status==not_exec && p[i].at <= ct)
				p[i].wt++;
			}
			ct++;
			p[spidx].ft=ct-p[spidx].at;
			p[spidx].bt--;
			if(p[spidx].bt <= 0){
				p[spidx].ft = ct - p[spidx].at;
				p[spidx].status=exec;
			}

		}
	}while(ct <= sum);
}
void show(process *p,int *a,int n){
	printf("_______Sjf SCHEDULING_______\n");
	printf("Pid\tArr Time\tBurst Time\tTurnArTime\tWait Time\n");
	for(int i=0;i < n;i++){
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,a[i],p[i].ft,p[i].wt);
	}
}
int main(){
	int n,*a;
	process *p;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	p=(process *)malloc(n*sizeof(process));
	for(int i=0;i<n;i++){
		p[i].pid=i+1;
		scanf("%d %d",&p[i].at,&p[i].bt);
		a[i]=p[i].bt;
	}
	solve(p,n);
	show(p,a,n);
}