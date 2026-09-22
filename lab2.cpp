#include <iostream>
using namespace std;
int main()
{ system("chcp 65001 > nul");
    const int N=100;
double m[N];
int n;
cout<<"n= ";
cin>>n;
if (n<=N&&n>0){
cout<<"с клавиатуры(1) или случайным образом(2)?\n";
int h;
cin>>h;
if (h==1)
{
for (int i=0;i<n;i++){
    cout<<i<<':';
    cin>>m[i];
    
}
}
else if(h==2){
    double a,b;
    cout<<"a=";
    cin>>a;
    cout<<"b(b>a)=";
    cin>>b;
    srand(time(0));
for (int i=0;i<n;i++){
    
    
    
    //m[i]=rand()%(b-a+1)+a;
m[i]=rand()%(1001);
m[i]/=1000.0;//m[i]->[0;1]
m[i]*=b-a;
m[i]+=a;
    
}
}else
{
    cout<<"error\n";
    return 0;
}
//вывод
for (int i=0;i<n;i++){
    cout<<m[i]<<' ';    
}
cout<<endl;
//task1
double sum=0;
for (int i=0;i<n;i++){
if(m[i]>0){
    sum+=m[i];
}
}

cout<<"сумма положительных элементов: "<<sum <<endl;
//task2
int idx_max = 0;
int idx_min = 0;
for (int i = 1; i < n; i++) {
if (abs(m[i]) > abs(m[idx_max])) {
            idx_max = i;
        }
if (abs(m[i]) <= abs(m[idx_min])) {
            idx_min = i;
        }
    }

    cout << "\nПервый макс. по модулю: m[" << idx_max << "] = " << m[idx_max] << endl;
    cout << "Последний мин. по модулю: m[" << idx_min << "] = " << m[idx_min] << endl;

    int first_idx = min(idx_max, idx_min);
    int last_idx = max(idx_max, idx_min);

    if (last_idx - first_idx <= 1) {
        cout << "2. Между первым макс. и последним мин. по модулю нет элементов для перемножения." << endl;
    } else {
        double prod = 1.0;
        for (int i = first_idx + 1; i < last_idx; i++) {
            prod *= m[i];
        }
        cout << "2. Произведение элементов между ними: " << prod << endl;
    }
//task3
for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (m[i] < m[j]) {
                swap(m[i], m[j]);
            }
        }
    }
cout << "\nОтсортированные элементы с нечетными номерами :\n";
    for (int i = 0; i < n; i += 2) {
        cout << "№" << (i + 1) << ": " << m[i] << endl;
    }
    return 0;
}

else{
    cout<<"error"<<endl;
}

}