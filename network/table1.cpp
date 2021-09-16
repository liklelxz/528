#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int n = 6;
const int l = 1000;
char name[n] = {'u','v','w','x','y','z'};


int a[n][n]={    {l,2,5,1,l,l},
			 	 {2,l,3,2,l,l},
			 	 {5,3,l,3,1,5},
			 	 {1,2,3,l,1,l},
			 	 {l,l,1,1,l,2},
			 	 {l,l,5,l,2,l}};

int dv[n-1];			 	 
vector<int> dn;
vector<int> N;

void printfl(char N){
	cout<<"Step    "<<"N\'    ";
	int i=0;
	while (i<n){
		if(name[i]!=N){
			cout<<"D("<<name[i]<<"),p("<<name[i]<<")    ";
			i++;
		}
		else i++;
	}
	cout<<endl;
}
int get_index(char N){
	int i = 0;
	while(i<n){
		if(name[i]=N){
			return i;
		}
        i++;
	}
	
	
}
void make_step(int s, int s_n){
	cout<<s;
	int i = s;
	while(7-i-1>=0){
		cout<<" ";
		i++;
	}
	for (int j = 0; j<N.size();j++){
		cout<<name[N[j]];
	}
	cout<<"    ";
	for (int k = 0; k<n;k++){
		if(k ==s_n){
			continue;
		}
		else if(find(N.begin(),N.end(),k)!=N.end()){
			cout<<"    ";
		}
		else if(dv[k] >500){
			cout<<"1000";
		}
		else{
			cout<<dv[k]<<","<<name[k];
		}
		cout<<"    "; 
	}
	
	cout<<endl;
}
void update_dv(int s,int s_n){
	if (s==0){
		N.push_back(s_n);
		dn.erase(remove(dn.begin(),dn.end(),s_n),dn.end());
		for(int i = 0;i<dn.size();i++){
			dv[i] = a[s_n][dn[i]];
		}
	}
	else if(s > 0) {
		for(int j=0;j<n-1;j++){
			if(find(N.begin(),N.end(),k)!=N.end()){
				contine;
			}
		}
	}
}


int main(void){
	char in_node;
	cin>>in_node;
	int s_n = get_index(in_node);
	



}

