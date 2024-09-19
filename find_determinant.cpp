#include <iostream>
using namespace std;

class matrix{
    int n,i,j;
    int mat[10][10];
public:
    matrix(){
        //making matrix & taking values
        cout<<"Enter order of square matrix(<10): ";
        cin>>n;
        for(i=0; i<n; i++){
            cout<<"Enter elements of row "<<i<<":"<<endl;
            for(j=0; j<n; j++)
                cin>>mat[i][j];
        }
        //cout<<"data collection completed successfully."<<endl;
    }

private:
    int sum;
    int calc_i_details(int a){
        sum=0;
        for(j=1; j<=n; j++)
            sum = sum*10 + a;
        return sum;
    }

    void calc_det(){
        int i_start=calc_i_details(1), i_end=calc_i_details(n);
        //cout<<"starting i is: "<<i_start<<endl;
        //cout<<"ending i is: "<<i_end<<endl;
        int deter=0, prod, all[n], in_all, k, last_digit, sign_factor=1, no_of_prods=0;
        for (i=i_start; i<=i_end; i++){
            //checking if no 2 elements are of the same column, checking valid i
            //cout<<"checking i value: "<<i<<endl;
            for(j=0; j<n; j++)
                    all[j]=0;
            for(j=i; j>0; j/=10){
                last_digit=j%10;
                in_all=0;
                if((last_digit>n)||(last_digit==0)){
                    in_all=1;
                    //cout<<"in_all since i is not a valid digit"<<endl;
                    break;
                }
                for(k=n-1; k>=0; k--){
                    if(all[k]==last_digit){
                        in_all=1;
                        //cout<<"in_all since i is repeated"<<endl;
                        break;
                    }
                    if(all[k]==0){
                        all[k]=last_digit;
                        break;
                    }
                }
                if(in_all)
                    break;
                //else
                    //cout<<"not in_all declared"<<endl;
            }
            //checked.
            if(!in_all){
                //cout<<"valid no: "<<i<<endl;
                //cout<<"corresponding all array:"<<endl;
                prod=1;
                for(j=0; j<n; j++)
                    prod*=mat[j][all[j]-1];
                //cout<<"prod: "<<prod<<endl;
                prod*=sign_factor;
                no_of_prods++;
                if(no_of_prods%2!=0)
                    sign_factor*= -1;
                deter+=prod;
            }
        }
        cout<<"The determinant is: "<<deter;
    }
public:
    void det(){
        calc_det();
    }
};

int main(){
    matrix alpha;
    //cout<<"back to the main function"<<endl;
    alpha.det();
    return 0;
}
