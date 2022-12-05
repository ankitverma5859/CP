#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin>>m>>n;
	
  /*
  T shape is as below:
  (i,j) (i, j+1)   (i, j+2)
        (i+1, j+1)
        (i+2), j+1)
        (i+3, j+1)
  */
  
  //If number of rows is less than 4 or number of cols is less than 3 then no T shape can be formed hence return 0;
	if(m<4 or n<3) return 0;
	
	vector<vector<int>> mat(m, vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			mat[i][j] = a;
		}
	}

  //Find the max sum.
	int max_sum = INT_MIN;
	for(int i=0;i<m;i++){
		if(i<=m-4){
			for(int j=0;j<n;j++){
				if(j<=n-3){
					max_sum = max(max_sum, mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j+1] + mat[i+3][j+1]);
				}			
			}	
		}
	}
	
	cout<<"Max Sum: "<<max_sum<<endl;
	return 0;
}
