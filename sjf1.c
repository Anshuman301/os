#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define not_exec 0
#define exec 1

int sumBt(int *b,int n){
	int sum = 0;
	for(int i=0;i < n;i++){
		sum+=b[i];
	}
	return sum;
}

int firstArrProcess(int *at,int *bt,int *status,int n,int ct){
	int min=INT_MAX,pos=-1;
	for(int i=0; i< n;i++){
		if(status[i]==not_exec && ct>=at[i] && min >= bt[i]){
			min=bt[i];
			pos=i;
		}
	}
	// printf("pos:-%d \n",pos);
	return pos;
}

void solve(int *at,int *bt,int *wt,int *ft,int *status,int n){
	int ct=0,sum,spidx;
	sum = sumBt(bt,n);
	/*Initial process are not executed*/
	do{
		spidx = firstArrProcess(at,bt,status,n,ct);
		if(spidx == -1){
			ct++;
			continue;
		}
		else{
			for(int i=0;i<n;i++){
			if(i!=spidx && status[i]==not_exec && at[i] <= ct)
				wt[i]++;
			}
			ct++;
			ft[spidx]=ct-at[spidx];
			bt[spidx]--;
			if(bt[spidx] <= 0){
				ft[spidx] = ct - at[spidx];
				status[spidx] = exec;
			}

		}
	}while(ct <= sum);
}

void show(int *pid,int *at,int *bt,int *wt,int *ft,int n){
	int sum1 =0,sum2 = 0,avgft=0,avgwt = 0;
	for(int i=0 ; i<n;i++){
		sum1+=wt[i];
		sum2+=ft[i];
	}
	avgwt = sum1/n;
	avgft = sum2/n;
	printf("_______Sjf SCHEDULING_______\n");
	printf("Pid\tArr Time\tBurst Time\tTurnArTime\tWait Time\n");
	for(int i=0;i < n;i++){
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i],ft[i],wt[i]);
	}
	printf("Average Waiting time : %d\n",avgwt);
	printf("Average Turn Around Time: %d\n",avgft);
}
int main(){
	int n;
	scanf("%d",&n);
	int *at = (int *)malloc(n*sizeof(int));
	int *bt = (int *)malloc(n*sizeof(int));
	int *wt = (int *)calloc(n,sizeof(int));
	int *tat = (int *)calloc(n,sizeof(int));
	int *status = (int *)calloc(n,sizeof(int));
	int *pid = (int *)calloc(n,sizeof(int));
	int *tempBt = (int *)calloc(n,sizeof(int));
	for(int i=0;i < n;i++){
		scanf("%d %d",&at[i],&bt[i]);
		pid[i] = i+1;
		tempBt[i] = bt[i];
	}
	solve(at,bt,wt,tat,status, n);
	show(pid,at,tempBt,wt,tat,n);
}