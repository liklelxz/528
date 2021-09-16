#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;
void printfl(char N);
int gi(char N);
void makestep(int s,char NO[]);
int getD(int s, char NO[]);
char addnu(int s, char NO[]);
void initialDO(char N);
const int n = 6;
const int l = 1000;
const char v[n]={'u','v','w','x','y','z'};
int a[6][6]={     {l,2,5,1,l,l},
			 	 {2,l,3,2,l,l},
			 	 {5,3,l,3,1,5},
			 	 {1,2,3,l,1,l},
			 	 {l,l,1,1,l,2},
			 	 {l,l,5,l,2,l}};
int D[n]={};
char DN[n]={};
int main(void){
	int i = 0;
	int j = 0;
	
	char N;
	cin >>N;
	
	printfl(N);
	char NO[n]={N};
	int s = 0;
	while(s<=n-1){
		getD(s,NO);
		makestep(s,NO);
		if(s<=n-2){
			NO[s+1]= addnu(s,NO);
		}
		s+=1;
	}
}

void printfl(char N){
	cout<<"Step    "<<"N\'    ";
	int i=0;
	while (i<n){
		if(v[i]!=N){
			cout<<"D("<<v[i]<<")    ";
			i++;
		}
		else i++;
	}
	cout<<endl;
}
int gi(char N){
	int i = 0;
	while(i<=n-1){
		if(N==v[i]) return i;
		else i++;
	}
}

void makestep(int s,char NO[]){
	cout<<s;
	int i = s;
	int j = 0;
	int sa = 0;
	
	while(6-i-1>=0){
		cout<<" ";
		i++;
	}
	i = 0;
	while(i<=s){
		cout<<NO[i];
		i++;
	}
	cout<<"     ";
	i=0;
	while(i<=n-1){
		while(j<=n-1){
			if (v[i]==NO[j]){
				sa=1;
				j++;
			}
			else{
				j++;
			}
		}
		if(sa==1){
			sa=0;
			i++;
		}
		else if(D[i]<1000){
			cout<<D[i]<<","<<DN[i]<<"     ";
			i++;
		}
		else{
			cout<<D[i]<<"    ";
			i++;
		}
		
	}
	cout<<endl;
}

int getD(int s, char NO[]){
	int k=0;
	int i = 0;
	if (s ==0){
		while(k<=n-1){
			if(k!=gi(NO[s])){
				D[k]=(a[gi(NO[s])][k]);
				if(D[k]<1000) DN[k]=NO[s];
				k++;
			}
			else{
				D[k]=0;
				k++;
			}
		}
	}
	else if(s>0)
	{	
		while(i<=n-1){
		if(D[i]<(D[gi(NO[s])]+a[gi(NO[s])][i])){
		i++;
		}
		else{
		D[i]=(D[gi(NO[s])]+a[gi(NO[s])][i]);
		DN[i]=v[gi(NO[s])];
		i++;
		}
		
	}
	}
}

char addnu(int s,char NO[]){
	int i = 0;
	int j = 0;
	int sa = 0;
	int smallest=100;
	while(i<=n-1){
		j=0;
		while(j<=s){
			if(v[i]!=NO[j]){
				j++;
			}
			else{
				sa = 1;
				j++;
			}
		}
		if(sa==1){
			sa = 0;
			i++;
		}
		else if(smallest==100){
			smallest=i;
			i++;
		}
		else{
			if(D[smallest]>D[i]){
				smallest = i;
				i++;
			}
			else i++;
		}
	}
	return v[smallest];
}


