#include <bits/stdc++.h>
using namespace std;

class bill
{
public:
    int qua, tqua;
    int price;
    int tprice[10], pri[10], quan[10];
    string name, nam[10];
    int total = 0;
    int TodaysSell[100];
    int toSell = 0;

    fstream f;

    // void output()
    // {
    //     cout<<"\n-----------------------------------------"<<endl;
    //     cout<<"\t***List of Items***\n";
    //     cout<<"-----------------------------------------"<<endl;

    //    cout<<"\tName\t\tPrice\t\tQty\n";
    //    for(int i=0; i<tqua; i++)
    //    {
    //       cout<<"\t"<<nam[i]<<"\t\t"<<pri[i]<<"\t\t"<<quan[i]<<endl;
    //    }
    // }

    void input();
    void billcal();
    void billdisplay();
    void payment();
    void toDaysSell();
};

void bill ::billcal()
{
    f.open("oops.txt", ios::app);

    f << "\n--------------------------------------------------------------" << endl;
    f << "\t\t*** List of Items ***\n";
    f << "--------------------------------------------------------------" << endl;

    f << setw(15) << "Name" << setw(15) << "Price" << setw(15) << "Qty" << setw(15) << "Total Qty" << endl;
    for (int i = 0; i < tqua; i++)
    {
        tprice[i] = pri[i] * quan[i];
    }

    for (int i = 0; i < tqua; i++)
    {
        total = total + tprice[i];
    }

    TodaysSell[toSell] = total;
    toSell++;

    for (int i = 0; i < tqua; i++)
    {
        f << setw(15) << nam[i] << setw(15) << pri[i] << setw(15) << quan[i] << setw(15) << tprice[i] << "\n";
    }
    f << "\n--------------------------------------------------------------" << endl;
    f << setw(55) << "Total Bill:" << total << endl;
}

void bill::input()
{

    cout << "\nEnter the Total no. of Items:";
    cin >> tqua;

    for (int i = 0; i < tqua; i++)
    {
        cout << "\n\t**Details of"
             << " " << i + 1 << " "
             << "Item**" << endl;
        cout << "\nEnter the Name of "
             << "Item:";
        cin >> name;
        nam[i] = name;
        // f.write(reinterpret_cast<char *>(&nam[i]), sizeof(nam[i]));
        //    f << nam[i]<<" ";

        cout << "\nEnter the Price of Item:";
        cin >> price;
        pri[i] = price;
        // f.write((pri[i]), sizeof(pri[i]));
        //  f << pri[i]<<" ";

        cout << "\nEnter the Total Quantity of Item:";
        cin >> qua;
        quan[i] = qua;
        // f.write(reinterpret_cast<char *>(&quan[i]), sizeof(quan[i]));
        //  f << quan[i] << endl;
    }
    // f.close();
}

void bill ::billdisplay()
{
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "\t\t*** List of Items ***\n";
    cout << "--------------------------------------------------------------" << endl;

    // f.open("oops.txt");

    cout << setw(15) << "Name" << setw(15) << "Price" << setw(15) << "Qty" << setw(15) << "Total Qty" << endl;

    for (int i = 0; i < tqua; i++)
    {
        // f.read(reinterpret_cast<char *>(&nam[i]), sizeof(nam[i]));
        // f.read(reinterpret_cast<char *>(&pri[i]), sizeof(pri[i]));
        // f.read(reinterpret_cast<char *>(&quan[i]), sizeof(quan[i]));

        cout << setw(15) << nam[i] << setw(15) << pri[i] << setw(15) << quan[i] << setw(15) << tprice[i] << "\n";
    }
    cout << "\n--------------------------------------------------------------" << endl;
    cout << setw(55) << "Total Bill:" << total << endl;
    // f.close();
}

void bill ::payment()
{
    int cash, more;
    int jast = 0;
    int ch;
    int amt;

    cout << "\n----------------------------------------------------" << endl;
    cout << "\t\t*** Payment ***\n";
    cout << "----------------------------------------------------" << endl;

    cout << "Select Payment Method:";
    cout << "\n\t1)Phone Pay\n\t2)Google Pay\n\t3)Cash Payment\nEnter Your Choice:";
    cin >> ch;

    switch (ch)
    {

    case 1:

        cout << "\nSelected Payment Method: Phone Pay\n";
        cout << "\nEnter the Amount to Pay:";
        cin >> amt;

        if (amt < total)
        {
            cout << "\nPlease Enter FUll Bill this is Not sufficient";
        }
        else
        {
            cout << "\n\tPayment Successful..!!\n";
            cout << "\n\n\tThank You For Visiting....Please Visit Again\n\n";
        }

        break;

    case 2:

        cout << "\nSelected Payment Method: Google Pay\n";
        cout << "\nEnter the Amount to Pay:";
        cin >> amt;

        if (amt < total)
        {
            cout << "\nPlease Enter FUll Bill this is Not sufficient";
        }
        else
        {
            cout << "\n\tPayment Successful..!!\n";
            cout << "\n\n\tThank You For Visiting....Please Visit Again\n\n";
        }

        break;

    case 3:
        cout << "\nEnter the Total Amount To give to shopkeeper:";
        cin >> cash;

        if (cash < total)
        {
            cout << "\nThe Given Money is Not Enough"
                 << " ";
            more = total - cash;
            cout << more << "Rs more  Needed" << endl;
        }
        else if (cash == total)
        {
            cout << "\nPayment Successful..!!\n";
            cout << "\n\n\n\tThank You For Visiting....Please Visit Again\n\n";
        }
        else
        {
            jast = cash - total;
            cout << "\nPayment  Successful....but you Give " << jast << "Rs Extra Take It Change..!!";
            cout << "\n\n\tThank You For Visiting....Please Visit Again\n\n";
        }

        break;
    default:
        cout << "Invalid Choice is Selected..please Select Correct choice";
    }
    // f.close();
}

int main()
{
    int ch;
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "\t\t*** Welcome to Store ***\n";
    cout << "--------------------------------------------------------------" << endl;
    bill b;
    b.input();
    b.billcal();
    b.billdisplay();
    b.payment();



    // cout << "\nYou Want to Display today's Total Sell:\n1)Yes\n2)No\n\nEnter your Choice:";
    // cin >> ch;
    // if (ch == 1)
    // {
    //     b.toDaysSell();
    //     cout << "\tIt Display on The File\n";
    //     cout << "\t Thank You...";
    // }
    // else
    // {
    //     cout << "\nThank You..!!";
    // }
    return 0;
}