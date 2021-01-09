#include <bits/stdc++.h>
using namespace std;
struct patient
{
    int id;
    char fname[20];
    char lname[20];
    int age;
    char gender;
    char date[15];
    char st[20];
};
bool cmp(struct patient &p, struct patient &q)
{
    return (p.id < q.id);
}
bool cmpd(struct patient &p, struct patient &q)
{
    return (p.id > q.id);
}
void listasc(int n)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct patient arr[n];
    struct patient p;
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        strcpy(arr[i].fname, p.fname);
        strcpy(arr[i].lname, p.lname);
        arr[i].age = p.age;
        arr[i].id = p.id;
        strcpy(arr[i].date, p.date);
        strcpy(arr[i].st, p.st);
        arr[i].gender = p.gender;
        i++;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << "First Name:" << arr[i].fname << endl;
        cout << "Last Name:" << arr[i].lname << endl;
        cout << "Age:" << arr[i].age << endl;
        cout << "Date:" << arr[i].date << endl;
        cout << endl;
    }
    fclose(fp);
}
void listdsc(int n)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct patient arr[n];
    struct patient p;
    int i = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        strcpy(arr[i].fname, p.fname);
        strcpy(arr[i].lname, p.lname);
        arr[i].age = p.age;
        arr[i].id = p.id;
        strcpy(arr[i].st, p.st);
        strcpy(arr[i].date, p.date);
        arr[i].gender = p.gender;
        i++;
    }
    sort(arr, arr + n, cmpd);
    for (int i = 0; i < n; i++)
    {
        cout << "First Name:" << arr[i].fname << endl;
        cout << "Last Name:" << arr[i].lname << endl;
        cout << "Age:" << arr[i].age << endl;
        cout << "Date:" << arr[i].date << endl;
        cout << endl;
    }
    fclose(fp);
}
void seprec()
{
    FILE *fp, *fm, *ff;
    fp = fopen("data.txt", "r");
    fm = fopen("male.txt", "ab");
    ff = fopen("female.txt", "ab");
    struct patient p;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        if (p.gender == 'M')
        {
            fwrite(&p, sizeof(struct patient), 1, fm);
        }
        else if (p.gender == 'F')
        {
            fwrite(&p, sizeof(struct patient), 1, ff);
        }
    }
    fclose(fp);
    fclose(fm);
    fclose(ff);
}
void range_name()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct patient p;
    int f = 0;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        char fnm[20];
        strcpy(fnm, p.fname);
        if (((fnm[0] >= 'S' && fnm[0] <= 'Z') || (fnm[0] >= 's' && fnm[0] <= 'z')) || ((fnm[0] >= 'A' && fnm[0] <= 'B') || (fnm[0] >= 'a' && fnm[0] <= 'b')))
        {
            f = 1;
            cout << "Name: " << p.fname << " " << p.lname << endl;
            cout << "Age: " << p.age << endl;
            cout << "Gender: " << p.gender << endl;
            cout << "Date of admission: " << p.date << endl;
            cout << endl;
        }
    }
    if (f == 0)
        cout << "No records found!" << endl;
    fclose(fp);
}
void range_date()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct patient p;
    int f = 0, dd;
    cout << "Enter a date (DD): ";
    cin >> dd;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        char dt[15];
        strcpy(dt, p.date);
        int t = (dt[0] - '0');
        t = t * 10;
        int tt = (dt[1] - '0');
        t = t + tt;
        if ((t >= dd && t <= 30) || (t <= (dd + 10) % 30))
        {
            f = 1;
            cout << "Name: " << p.fname << " " << p.lname << endl;
            cout << "Age: " << p.age << endl;
            cout << "Gender: " << p.gender << endl;
            cout << "Date of admission: " << p.date << endl;
            cout << endl;
        }
    }
    if (f == 0)
        cout << "No records found!" << endl;
    fclose(fp);
}
void range_month()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct patient p;
    int f = 0, mn;
    cout << "Enter a month (MM): ";
    cin >> mn;
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        char dt[15];
        strcpy(dt, p.date);
        int t = (dt[3] - '0');
        t = t * 10;
        int tt = (dt[4] - '0');
        t = t + tt;
        if (t >= mn && t <= (mn + 5))
        {
            f = 1;
            cout << "Name: " << p.fname << " " << p.lname << endl;
            cout << "Age: " << p.age << endl;
            cout << "Gender: " << p.gender << endl;
            cout << "Date of admission: " << p.date << endl;
            cout << endl;
        }
    }
    if (f == 0)
        cout << "No records found!" << endl;
    fclose(fp);
}
int calc()
{
    int res = 0;
    FILE *fp;
    struct patient p;
    fp = fopen("data.txt", "r");
    while (fread(&p, sizeof(struct patient), 1, fp) == 1)
    {
        res++;
    }
    return res;
    fclose(fp);
}
int main()
{
    struct patient p;
    FILE *fp, *ft;
    char ch;
    int rec = 0, tot = 0;
    char nm[20];
    char s1[20] = "Gujarat";
    char s2[20] = "gujarat";
    int an;
    int f = 0, flag = 0, idd;
    int cnt = 0, mcnt = 0, fcnt = 0, lecnt = 0, mecnt = 0, ig = 0, og = 0;
    while (1)
    {
        cout << "1. Add record" << endl;
        cout << "2. Delete record" << endl;
        cout << "3. Modify record" << endl;
        cout << "4. Summary Report" << endl;
        cout << "5. List (Ascending order)" << endl;
        cout << "6. List (Descending order)" << endl;
        cout << "7. Data in Range" << endl;
        cout << "8. Separate record of M/F" << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "Enter your choice :";
        cin >> ch;
        switch (ch)
        {
        case '1':
            fp = fopen("data.txt", "ab");
            while (1)
            {
                cout << "Enter first name: " << endl;
                cin >> p.fname;
                fflush(stdin);
                cout << "Enter last name: " << endl;
                cin >> p.lname;
                fflush(stdin);
                cout << "Enter patient id: " << endl;
                cin >> p.id;
                fflush(stdin);
                cout << "Enter age: ";
                cin >> p.age;
                fflush(stdin);
                cout << "Enter Gender(M/F): ";
                cin >> p.gender;
                fflush(stdin);
                cout << "Enter date (DD/MM/YY): " << endl;
                cin >> p.date;
                fflush(stdin);
                cout << "Enter state: " << endl;
                cin >> p.st;
                fflush(stdin);
                fwrite(&p, sizeof(struct patient), 1, fp);
                fflush(stdin);
                cout << "Record Added!" << endl;
                cout << "Enter more record y/n?" << endl;
                char c;
                cin >> c;
                if (c == 'n' || c == 'N')
                    break;
            }
            fclose(fp);
            break;
        case '2':
            cout << "Enter the ID of person to delete from record: ";
            cin >> idd;
            fp = fopen("data.txt", "r");
            ft = fopen("temp.txt", "ab");
            flag = 0;
            while (fread(&p, sizeof(struct patient), 1, fp) == 1)
            {
                if (p.id != idd)
                {
                    fwrite(&p, sizeof(struct patient), 1, ft);
                }
                else
                    flag = 1;
            }
            fclose(fp);
            fclose(ft);
            if (flag == 0)
            {
                cout << "Record not found!" << endl;
                break;
            }
            remove("data.txt");
            rename("temp.txt", "data.txt");
            cout << "Record deleted Successfully!" << endl;
            break;
        case '3':
            rec = 0;
            cout << "Enter ID of patient to modify record: ";
            cin >> idd;
            fp = fopen("data.txt", "rb+");
            f = 0;
            while (fread(&p, sizeof(struct patient), 1, fp) == 1)
            {
                if (p.id == idd)
                {
                    f = 1;
                    cout << "Enter new first name: ";
                    cin >> p.fname;
                    fflush(stdin);
                    cout << "Enter new last name: ";
                    cin >> p.lname;
                    fflush(stdin);
                    cout << "Enter new age: ";
                    cin >> p.age;
                    fflush(stdin);
                    cout << "Enter new gender: ";
                    cin >> p.gender;
                    fflush(stdin);
                    cout << "Enter new date: ";
                    cin >> p.date;
                    fflush(stdin);
                    cout << "Enter new state: ";
                    cin >> p.st;
                    fflush(stdin);
                    fseek(fp, sizeof(struct patient) * rec, SEEK_SET);
                    fwrite(&p, sizeof(struct patient), 1, fp);
                    break;
                }
                rec++;
            }
            if (f == 0)
            {
                cout << "Record not found!" << endl;
            }
            else
                cout << "Record Updated Successfully!!";
            fclose(fp);
            break;
        case '4':
            cnt = 0;
            mcnt = 0;
            fcnt = 0;
            lecnt = 0;
            mecnt = 0;
            ig = 0;
            og = 0;
            fp = fopen("data.txt", "r");
            while (fread(&p, sizeof(struct patient), 1, fp) == 1)
            {
                cnt++;
                if (p.gender == 'M')
                    mcnt++;
                else if (p.gender == 'F')
                    fcnt++;
                if (p.age <= 18 && p.age > 0)
                    lecnt++;
                else
                    mecnt++;
                if (strcmp(s1, p.st) == 0 || strcmp(s2, p.st) == 0)
                    ig++;
                else
                    og++;
            }
            cout << "No of patient: " << cnt << endl;
            cout << "No of male patient: " << mcnt << endl;
            cout << "No of female patient: " << fcnt << endl;
            cout << "No of patient of age <= 18: " << lecnt << endl;
            cout << "No of patient of age > 18: " << mecnt << endl;
            cout << "No of petient inside gujarat: " << ig << endl;
            cout << "No of patient outside gujarat: " << og << endl;
            fclose(fp);
            break;
        case '5':
            tot = calc();
            listasc(tot);
            break;
        case '6':
            tot = calc();
            listdsc(tot);
            break;
        case '7':
            cout << "1. According to first name: " << endl;
            cout << "2. According to user given date: " << endl;
            cout << "3. According to user given month: " << endl;
            cout << "Enter choice(1-3): ";
            cin >> an;
            if (an == 1)
            {
                range_name();
            }
            else if (an == 2)
            {
                range_date();
            }
            else if (an == 3)
            {
                range_month();
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
            break;
        case '8':
            seprec();
            cout << "Records are separed successfully!";
            break;
        case '9':
            exit(0);
        default:
            cout << "Invalid choice: " << endl;
        }
    }
}