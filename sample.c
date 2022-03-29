#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int S[]={7,12,19,3,18,4,2,6,15,8};

void *Sorting0(int arr[]){
	int save;
	for(int i=0;i<5;i++){
		for(int k=0;k<4;k++){
			if(arr[k+1]<arr[k]){
				save = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = save; 
			}
		}
	}
}

void *Sorting1(int arr[]){
	int save;
	for(int i=1;i<5;i++){
		for(int k=0;k<4;k++){
			if(arr[k+1]<arr[k]){
				save = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = save; 
			}
		}
	}
}

void *Merge(int arr[]){
	int save;
	for(int i=1;i<10;i++){
		for(int k=0;k<9;k++){
			if(arr[k+1]<arr[k]){
				save = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = save; 
			}
		}
	}	
}

int main(){
	pthread_t t0,t1,M;
	int s0[5],s1[5],m[10];
	for(int i=0;i<10;i++){
		if(i<5) s0[i] = S[i];
		else s1[i-5] = S[i];
	}
	for(int i=0;i<10;i++){
		if(i<5) m[i] = s0[i];
		else m[i] = s1[i-5];
	}
	pthread_create(&t0, NULL, Sorting0, (void *) &s0);
	pthread_create(&t1, NULL, Sorting1, (void *) &s1);
	pthread_create(&M, NULL, Merge, (void *) &m);
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(M, NULL);
	//for(int i=0;i<5;i++) printf("First: %d\n",s0[i]);
	//for(int j=0;j<5;j++) printf("Second: %d\n",s1[j]);
	for(int k=0;k<10;k++) printf("Merge: %d\n",m[k]);
	return 0;
}
	
