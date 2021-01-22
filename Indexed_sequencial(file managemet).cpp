#include <bits/stdc++.h>
using namespace std;
struct patient
{
    int id;
    char fname[20];
    char lname[20];
    int age;
    char doc_name[20];
    char gender;
    long long int mobile;
    char datea[10];
    char dated[10];
    char addr[30];
};
struct indx
{
    long long int mob;
    int pos;
};
bool cmp(struct indx &p, struct indx &q)
{
    return (p.mob < q.mob);
}
int calc()
{
    int res = 0;
    FILE *fp;
    struct patient p;
    fp = fopen("data.txt", "rb+");
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        res++;
    }
    return res;
    fclose(fp);
}
void sortasce()
{
    int n = calc();
    struct indx arr[n];
    struct indx p;
    FILE *fp = fopen("index.txt", "rb+");
    int i = 0;
    while (fread(&p, sizeof(struct indx), 1, fp) == 1)
    {
        arr[i].mob = p.mob;
        arr[i].pos = p.pos;
        i++;
    }
    fclose(fp);
    sort(arr, arr + n, cmp);
    FILE *ft = fopen("temp.txt", "ab+");
    for (int i = 0; i < n; i++)
    {
        p.mob = arr[i].mob;
        p.pos = arr[i].pos;
        fwrite(&p, sizeof(struct indx), 1, ft);
    }
    fclose(ft);
    remove("index.txt");
    rename("temp.txt", "index.txt");
}
void add_rec()
{
    struct patient p;
    struct indx pi;
    FILE *fp, *ft;
    char ans = 'y';
    fp = fopen("data.txt", "ab+");
    ft = fopen("index.txt", "ab+");
    int rec = calc();
    while (ans == 'y' || ans == 'Y')
    {
        cout << "Enter patient's ID : ";
        cin >> p.id;
        fflush(stdin);
        cout << "Enter patient's first name : ";
        cin >> p.fname;
        fflush(stdin);
        cout << "Enter patient's last name : ";
        cin >> p.lname;
        fflush(stdin);
        cout << "Enter age : ";
        cin >> p.age;
        fflush(stdin);
        cout << "Enter patient's doctor name : ";
        cin.getline(p.doc_name, 19);
        fflush(stdin);
        cout << "Enter patient's gender (M/F) : ";
        cin >> p.gender;
        fflush(stdin);
        cout << "Enter mobile no : ";
        cin >> p.mobile;
        pi.mob = p.mobile;
        pi.pos = rec;
        rec++;
        fflush(stdin);
        cout << "Enter patient's admit date (DD-MM-YY) : ";
        cin >> p.datea;
        fflush(stdin);
        cout << "Enter patient's dep date (DD-MM-YY) : ";
        cin >> p.dated;
        fflush(stdin);
        cout << "Enter patient's adress : ";
        cin.getline(p.addr, 29);
        fwrite(&p, sizeof(struct patient), 1, fp);
        fwrite(&pi, sizeof(struct indx), 1, ft);
        fflush(stdin);
        cout << "Recod added !! " << endl;
        cout << "Wanna enter more (y/n) : ";
        cin >> ans;
    }
    fclose(fp);
    fclose(ft);
    sortasce();
}
int search(long long int m, bool ret)
{
    FILE *fp;
    fp = fopen("index.txt", "rb+");
    int low = 0;
    int high = calc();
    high -= 1;
    int ans = -1;
    struct indx p;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        fseek(fp, (mid * sizeof(struct indx)), SEEK_SET);
        fread(&p, sizeof(struct indx), 1, fp);
        if (p.mob == m)
        {
            ans = p.pos;
            break;
        }
        else if (p.mob < m)
        {
            low = mid + 1;
        }
        else if (p.mob > m)
        {
            high = mid - 1;
        }
    }
    if (ret == true)
    {
        return ans;
    }
    if (ans == -1)
    {
        cout << "Record not found!" << endl;
        return -1;
    }
    //cout << ans << endl;
    fclose(fp);
    FILE *ft;
    ft = fopen("data.txt", "rb+");
    struct patient pa;
    fseek(fp, (ans * sizeof(struct patient)), SEEK_SET);
    fread(&pa, sizeof(struct patient), 1, ft);
    cout << "ID : " << pa.id << endl;
    cout << "Name : " << pa.fname << " " << pa.lname << endl;
    cout << "Age : " << pa.age << endl;
    cout << "Mobile : " << pa.mobile << endl;
    cout << "Doctor's name : " << pa.doc_name << endl;
    cout << "Date of admit : " << pa.datea << endl;
    cout << "Date of discharge : " << pa.dated << endl;
    cout << "Address : " << pa.addr << endl;
    fclose(ft);
}
void modify()
{
    long long int m;
    FILE *fp;
    fp = fopen("data.txt", "rb+");
    cout << "Enter the mobile no to modify the record: ";
    cin >> m;
    int pos = search(m, true);
    if (pos == -1)
    {
        cout << "Record not found!!" << endl;
        return;
    }
    struct patient p;
    cout << "Enter new ID : ";
    cin >> p.id;
    fflush(stdin);
    cout << "Enter new first name : ";
    cin >> p.fname;
    fflush(stdin);
    cout << "Enter new last name : ";
    cin >> p.lname;
    fflush(stdin);
    cout << "Enter new age : ";
    cin >> p.age;
    fflush(stdin);
    cout << "Enter new doctor's name : ";
    cin.getline(p.doc_name, 19);
    fflush(stdin);
    cout << "Enter new gender (M/F) : ";
    cin >> p.gender;
    fflush(stdin);
    p.mobile = m;
    cout << "Enter patient's admit date (DD-MM-YY) : ";
    cin >> p.datea;
    fflush(stdin);
    cout << "Enter patient's dep date (DD-MM-YY) : ";
    cin >> p.dated;
    fflush(stdin);
    cout << "Enter patient's adress : ";
    cin.getline(p.addr, 29);
    fseek(fp, (pos * sizeof(struct patient)), SEEK_SET);
    fwrite(&p, sizeof(struct patient), 1, fp);
    cout << endl;
    cout << "Record modified successfully!!" << endl;
    fclose(fp);
}
void del()
{
    long long int m;
    FILE *fp, *ft;
    struct patient p;
    fp = fopen("data.txt", "rb+");
    ft = fopen("temp.txt", "wb+");
    cout << "Enter the mobile number of patient to delete : ";
    cin >> m;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        if (p.mobile != m)
        {
            fwrite(&p, sizeof(struct patient), 1, ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    fp = fopen("data", "rb+");
    ft = fopen("tmp.txt", "wb+");
    struct indx pi;
    int k = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        pi.mob = p.mobile;
        pi.pos = k;
        fwrite(&pi, sizeof(struct indx), 1, ft);
        k++;
    }
    fclose(fp);
    fclose(ft);
    remove("index.txt");
    rename("tmp.txt", "index.txt");
    cout << "Record deleted successfully!!" << endl;
    sortasce();
}
int main()
{
    long long int m;
    int ch;
    while (1)
    {
        cout << "1. Add record" << endl;
        cout << "2. Delete record" << endl;
        cout << "3. Modify record" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice :";
        cin >> ch;
        if (ch == 1)
        {
            add_rec();
        }
        else if (ch == 2)
        {
            del();
        }
        else if (ch == 3)
        {
            modify();
        }
        else if (ch == 4)
        {
            cout << "Enter the mobile no of patient to search: ";
            cin >> m;
            search(m, false);
        }
        else if (ch == 5)
        {
            exit(0);
        }
    }
}
