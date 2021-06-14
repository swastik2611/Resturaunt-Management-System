#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
class event_details
{
    public:
    int event_choice; //to store if guests have come for an event or not
    void input_event_choice()
    {
        cout << "Please make a choice from the options listed below : " << endl;
        cout << "Press 1 for Kitty Party" << endl;
        cout << "Press 2 for Birthday Party" << endl;
        cout << "Press 3 for Anniversary Party" << endl;
        cout << "Press 4 for Business Meetings" << endl;
        cout << "Press 5 for others" << endl;
        cin >> event_choice;
        cout << endl;
    }
    int event_check()
    {
        int cust_menu_choice;
        if (event_choice == 1)
        {
            cout << "We wish you a great Kitty Pary! " << endl<<endl;
            cout << "Would you like to get offered a customized menu for Kitty Party" << endl;
            cout << "Press 1 for YES, 2 for NO : ";
            cin >> cust_menu_choice;
            return cust_menu_choice;
        }
        else if (event_choice == 2)
        {
            cout << "HAPPY BIRTHDAY! " << endl<<endl;
            cout << "Would you like to get offered a customized menu for Birthday Party" << endl;
            cout << "Press 1 for YES, 2 for NO : ";
            cin >> cust_menu_choice;
            return cust_menu_choice;
        }
        else if (event_choice == 3)
        {
            cout << "HAPPY ANNIVERSARY! " << endl<<endl;
            cout << "Would you like to get offered a customized menu for Anniversary Party" << endl;
            cout << "Press 1 for YES, 2 for NO : ";
            cin >> cust_menu_choice;
            return cust_menu_choice;
        }
        else if (event_choice == 4)
        {
            cout << "We wish you a sucessful Meeting! " << endl<<endl;
            cout << "Would you like to get offered a customized menu for Bussiness Meeting" << endl;
            cout << "Press 1 for YES, 2 for NO : ";
            cin >> cust_menu_choice;
            return cust_menu_choice;
        }
        else
        {
            return 2;
        }
    }
};
class customer_details
{
    public:
    int no_of_members;
    int no_of_adults;
    int no_of_kids;
    string date;
    string m_name;
    long long ph_n;
    string day;
    void input_customer_details()
    {
        getchar();
        cout << endl << "Please enter your name : ";
        getline(cin, m_name);
        cout << "Please enter the total number of guests : ";
        cin >> no_of_members;
        cout << "Please enter the number of adults : ";
        cin >> no_of_adults;
        cout << "Please enter the number of kids(if any) : ";
        cin >> no_of_kids;
        try //to verify guests count
        {
            if ((no_of_adults + no_of_kids) != no_of_members || (no_of_adults < 0) || (no_of_kids < 0))
            {
                throw 0;
            }
        }
        catch (int a)
        {
            cout << "You have entered the wrong information about the number of members" << endl;
            exit(0);
        }
        cout << "Please enter the contact number : ";
        cin >> ph_n;
        cout << "Please enter the date : ";
        cin >> date;
        getchar();
        cout << "Please enter the day : ";
        getline(cin, day);
    }
};
class cuisine_details : public event_details, public customer_details
{
public:
    int cuisine_choice;

    vector<int> sno_cust[4]; //sno.
    vector<string> food[4];  //for customized menu
    double ph_adult[4];      //for per head adult
    double ph_kid[4];        //for per head kid
    double rate_cust;        //for rate of combo pack

    vector<int> price[4];      //normal price
    vector<int> sno[4];        //sno. for normal
    vector<double> rate[4];    //for rate
    vector<float> qty[4];      //for quantity
    vector<string> beverage;   //for bevergage
    vector<string> snck_strtr; //for snacks and starters
    vector<string> meal;       //for meal
    vector<string> dessert;    //for dessert
    int choice, quantity;      //to store the choice and quantity
    void input_menu()
    {
        cout << endl << "Please make a choice from options below : " << endl;
        cout << "Press 1 for Beverages " << endl;
        cout << "Press 2 for Snacks and Starters " << endl;
        cout << "Press 3 for Meals " << endl;
        cout << "Press 4 for Dessert " << endl;
        cin >> cuisine_choice;
    }
    void vector_intialization()
    {
        sno[0] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        beverage = {"Milk Shake ", "Cold Coffee ", "Fruit Juice ", "Lime Soda ", "Soft Drink ",
                    "Peach Collado ", "Green Valley ", "Spicy Guava ", "Berry Cooler ", "Blue Lady "};
        rate[0] = {110, 100, 70, 75, 80, 160, 170, 160, 150, 160};
        price[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        qty[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        sno[1] = {1, 2, 3, 4, 5};
        snck_strtr = {"Spring Roll      ", "French Onion Soup", "Tomato Bruschetta", "Ceaser Salad     ",
                      "Kebab            "};
        rate[1] = {150, 110, 120, 100, 110};
        price[1] = {0, 0, 0, 0, 0};
        qty[1] = { 0, 0, 0, 0, 0, };

        sno[2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        meal = {"Veg Hakka Noodles", "Veg Manchurian     ", "Chicken Chille     ",
                "Sweet and Sour Chicken", "Thai Veg Green Curry", "Thai Red Chicken Curry",
                "Chicken Tikka Masala  ", "Dal Makhni      ", "Jeera Aloo      ", "Paneer Butter Masala",
                "Butter Chicken     ", "Pizza           ", "Fish Pie          ", "Baked Vegetables     ",
                "Veg Stew           "};
        rate[2] = {110, 140, 160, 170, 120, 140, 130, 140, 120, 150, 180, 130, 160, 100, 210};
        price[2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        qty[2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        sno[3] = {1, 2, 3, 4, 5};
        dessert = {"Apple Pie with Cream", "Lemon Meringue Pie", "Ice Cream           ",
                   "Raj Bhog           ", "Faluda Kulfi           "};
        rate[3] = {105, 105, 120, 130, 110};
        price[3] = {0, 0, 0, 0, 0};
        qty[3] = { 0, 0, 0, 0, 0, };

        //custoized menu initialization
        sno_cust[0] = {1, 2, 3, 4, 5, 6, 7}; //kitty
        food[0] = {"Lime Water", "Achari Paneer Tikka", "Corn Kachori", "Samosa", "Peri Peri",
                   "Rava Dhokla", "Gulab Jamun"};
        ph_adult[0] = 380;
        ph_kid[0] = 220;

        sno_cust[1] = {1, 2, 3, 4, 5, 6, 7, 8}; //bday
        food[1] = {"Oreo Shake", "Coke", "Fries Pizza Puffs", "Mac & Cheese", "Chips", "Hakka Noodles",
                   "Deli Sushi Rolls", "Caramel Apple Stick"};
        ph_adult[1] = 320;
        ph_kid[1] = 180;

        sno_cust[2] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //annivr
        food[2] = {"Wine", "Zufrani Pulao", "Dal Bukhara", "Rissoto", "Dahi Baingan", "Chocolate Fondue",
                   "Butter Chicken  ", "Paan", "White Sauce Pasta"};
        ph_adult[2] = 400;
        ph_kid[2] = 250;

        sno_cust[3] = {1, 2, 3, 4, 5, 6, 7, 8}; //bus
        food[3] = {"Fruit Salad", "Thick Tomato Soup", "Lamb", "Prawns", "Paneer Lababdar",
                   "Idli Sambhar", "Flavoured Rice", "Garlic Breadsticks"};
        ph_adult[3] = 380;
        ph_kid[3] = 210;
    }
    int display_customized_menu()
    {
        int agr = 2;           //agreeed or not
        if (event_choice == 1) //kitty
        {
            cout << endl<< "Sno.\t\t"<< "Food Item\t\t\t" << endl;
            for (int i = 0; i < 7; i++)
            {
                cout << sno_cust[0][i] << "\t\t" << food[0][i] << endl;
            }
            cout << endl << "Cost per head for adults = " << ph_adult[0] << endl;
            cout << "Cost per head for kids   = " << ph_kid[0] << endl<< endl;
            cout << "Would you like to go ahead with the customized menu?" << endl;
            cout << "Press  1 for YES, 2 for NO : ";
            cin >> agr;
            cout << endl;
            return agr;
        }
        else if (event_choice == 2) //birthday
        {
            cout << endl << "Sno.\t\t" << "Food Item\t\t\t" << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << sno_cust[1][i] << "\t\t" << food[1][i] << endl;
            }
            cout << endl<< "Cost per head for adults = " << ph_adult[1] << endl;
            cout << "Cost per head for kids   = " << ph_kid[1] << endl<< endl;
            cout << "Would you like to go ahead with the customized menu?" << endl;
            cout << "Press  1 for YES, 2 for NO : ";
            cin >> agr;
            cout << endl;
            return agr;
        }
        else if (event_choice == 3) //anniversary
        {
            cout << endl<< "Sno.\t\t"<< "Food Item\t\t\t" << endl;
            for (int i = 0; i < 9; i++)
            {
                cout << sno_cust[2][i] << "\t\t" << food[2][i] << endl;
            }
            cout << endl << "Cost per head for adults = " << ph_adult[2] << endl;
            cout << "Cost per head for kids   = " << ph_kid[2] << endl<< endl;
            cout << "Would you like to go ahead with the customized menu?" << endl;
            cout << "Press  1 for YES, 2 for NO : ";
            cin >> agr;
            cout << endl;
            return agr;
        }
        else if (event_choice == 4) //meeting
        {
            cout << endl<< "Sno.\t\t"<< "Food Item\t\t\t" << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << sno_cust[3][i] << "\t\t" << food[3][i] << endl;
            }
            cout << endl<< "Cost per head for adults = " << ph_adult[3] << endl;
            cout << "Cost per head for kids   = " << ph_kid[3] << endl<< endl;
            cout << "Would you like to go ahead with the customized menu?" << endl;
            cout << "Press  1 for YES, 2 for NO : ";
            cin >> agr;
            cout << endl;
            return agr;
        }
        return agr;
    }
    void display_manual_menu()
    {
        int amt;
        if (cuisine_choice == 1) //beverage
        {
            cout << endl<<"Sno.\t\t" << "Name\t\t\t\t\t" << "Rate" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << sno[0][i] << "\t\t" << beverage[i] << "\t\t\t\tRs " << rate[0][i] << endl;
            }
            cout <<endl<< "Enter the Sno. to choose & 0 to finish" << endl;
            do
            {
                cout << "Enter Sno. : ";
                cin >> choice;
                if (choice != 0)
                {
                    cout << "Enter quantity : ";
                    cin >> quantity;
                    amt = quantity * rate[0][choice - 1];
                    price[0][choice - 1] = amt;
                    qty[0][choice - 1] = quantity;
                }
            } while (choice != 0);
        }
        else if (cuisine_choice == 2) //snacks
        {

            cout << endl<<"Sno.\t\t"<< "Name\t\t\t\t\t"<< "Rate" << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << sno[1][i] << "\t\t" << snck_strtr[i] << "\t\t\tRs " << rate[1][i] << endl;
            }
            cout << endl<<"Enter the Sno. to choose & 0 to finish" << endl;
            do
            {
                cout << "Enter Sno. : ";
                cin >> choice;
                if (choice != 0)
                {
                    cout << "Enter quantity : ";
                    cin >> quantity;
                    amt = quantity * rate[1][choice - 1];
                    price[1][choice - 1] = amt;
                    qty[1][choice - 1] = quantity;
                }
            } while (choice != 0);
        }
        else if (cuisine_choice == 3) //meal
        {

            cout <<endl<< "Sno.\t\t"<< "Name\t\t\t\t\t"<< "Rate" << endl;
            for (int i = 0; i < 15; i++)
            {
                cout << sno[2][i] << "\t\t" << meal[i] << "\t\t\tRs " << rate[2][i] << endl;
            }
            cout << endl<<"Enter the Sno. to choose & 0 to finish" << endl;
            do
            {
                cout << "Enter Sno. : ";
                cin >> choice;
                if (choice != 0)
                {
                    cout << "Enter quantity : ";
                    cin >> quantity;
                    amt = quantity * rate[2][choice - 1];
                    price[2][choice - 1] = amt;
                    qty[2][choice - 1] = quantity;
                }
            } while (choice != 0);
        }
        else if (cuisine_choice == 4) //dessert
        {

            cout <<endl<< "Sno.\t\t"<< "Name\t\t\t\t\t"<< "Rate" << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << sno[3][i] << "\t\t" << dessert[i] << "\t\t\tRs " << rate[3][i] << endl;
            }
            cout <<endl<< "Enter the Sno. to choose & 0 to finish" << endl;
            do
            {
                cout << "Enter Sno. : ";
                cin >> choice;
                if (choice != 0)
                {
                    cout << "Enter quantity : ";
                    cin >> quantity;
                    amt = quantity * rate[3][choice - 1];
                    price[3][choice - 1] = amt;
                    qty[3][choice - 1] = quantity;
                }
            } while (choice != 0);
        }
    }
    void cust_choice_menu()
    {
        if (event_choice == 1)
        {
            cout << endl<< "Thank you for choosing Kitty Party combo pack" << endl<<endl;
            cout << "\t\t\t\t***** Use promocode KITTY5 to avail 5% discount *****" << endl<<endl;
        }
        else if (event_choice == 2)
        {
            cout << endl << "Thank you for choosing Birthday Party combo pack" << endl<<endl;
            cout << "\t\t\t\t***** Use promocode BIRTHDAY5 to avail 5% discount ******" << endl<<endl;
        }
        else if (event_choice == 3)
        {
            cout << endl<< "Thank you for choosing Anniversary Party combo pack" << endl<<endl;
            cout << "\t\t\t\t***** Use  promocode ANNIVERSARY5 to avail 5% discount *****" << endl<<endl;
        }
        else
        {
            cout << endl<< "Thank you for choosing Business Party combo pack" << endl<<endl;
            cout << "\t\t\t\t***** Use promocode MEET5 to avail 5% discount *****" << endl<<endl;
        }
    }
    void manual_choice_menu()
    {
        int c = 0, serial = 1;
        cout << endl << "The menu that you have chosen is as follows" << endl;
        cout << "Beverages : " << endl<<endl;
        cout << "Sno.\t\t"<< "Beverage\t\t\t\t" << "Rate\t\t"<< "Quantity\t\t"<< "Price\t\t" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (qty[0][i] > 0)
            {
                c = 1;
                cout << serial++ << "\t\t" << beverage[i] << "\t\t\t\t" << rate[0][i] << "\t\t"
                     << qty[0][i] << "\t\t\t" << price[0][i] << endl;
            }
        }
        if (c == 0)
        {
            cout << endl<< "\t\t\t\t***** No choice from this category *****" << endl;
        }
        c = 0, serial = 1;
        cout << endl<< "Snacks and Starters : " << endl<<endl;
        cout << "Sno.\t\t"<< "Snacks & Starters\t\t\t"<< "Rate\t\t" << "Quantity\t\t"<< "Price\t\t" << endl;
        for (int i = 0; i < 5; i++)
        {
            if (qty[1][i] > 0)
            {
                c = 1;
                cout << serial++ << "\t\t" << snck_strtr[i] << "\t\t\t" << rate[1][i] << "\t\t"
                     << qty[1][i] << "\t\t\t" << price[1][i] << endl;
            }
        }
        if (c == 0)
        {
            cout << endl<< "\t\t\t\t***** No choice from this category *****" << endl;
        }
        c = 0, serial = 1;
        cout << endl<< "Main Course : " << endl<< endl;
        cout << "Sno.\t\t"<< "Main Course\t\t\t\t"<< "Rate\t\t"<< "Quantity\t\t" << "Price\t\t" << endl;
        for (int i = 0; i < 15; i++)
        {
            if (qty[2][i] > 0)
            {
                c = 1;
                cout << serial++ << "\t\t" << meal[i] << "\t\t\t" << rate[2][i] << "\t\t"
                     << qty[2][i] << "\t\t\t" << price[2][i] << endl;
            }
        }
        if (c == 0)
        {
            cout << endl<< "\t\t\t\t***** No choice from this category *****" << endl;
        }
        c = 0, serial = 1;
        cout << endl<< "Dessert : " << endl<<endl;
        cout << "Sno.\t\t"<< "Dessert\t\t\t\t\t"<< "Rate\t\t"<< "Quantity\t\t"<< "Price\t\t" << endl;
        for (int i = 0; i < 5; i++)
        {
            if (qty[3][i] > 0)
            {
                c = 1;
                cout << serial++ << "\t\t" << dessert[i] << "\t\t\t" << rate[3][i] << "\t\t"
                     << qty[3][i] << "\t\t\t" << price[3][i] << endl;
            }
        }
        if (c == 0)
        {
            cout << endl<< "\t\t\t\t***** No choice from this category *****" << endl;
        }
        c = 0, serial = 1;
        cout << endl;
    }
};
class Delivery
{
    public:
    string name;
    long long ph_no;
    string house_no;
    string street_name;
    long long pincode;
    string landmark;
    int delivery_choice;
    double delivery_charge;
    void input_delivery_address()
    {
        getchar();
        cout << "Please enter customer's name : ";
        getline(cin, name);
        cout <<endl<< "Give us your address details so that we can deliver the foood very soon" << endl;
        cout << "Please provide the following details" << endl<<endl;
        cout << "House number : ";
        cin >> house_no;
        getchar();
        cout << "Street name : ";
        getline(cin, street_name);
        cout << "Pincode:";
        cin >> pincode;
        getchar();
        cout << "Landmark : ";
        getline(cin, landmark);
        cout << "Contact number : ";
        cin >> ph_no;
    }
    void delivery_speed()
    {
        cout << endl << "\t\t\t\t****** Select from the following delivery speeds *****" << endl;
        cout << "Standard      : Free, Press 1 to choose" << endl;
        cout << "Express       : 3% of Bill(45 minutes delivery), Press 2 to choose" << endl;
        cout << "Super Express : 5% of Bill(30 minutes delivery), Press 3 to choose" << endl;
        cin >> delivery_choice;
        cout << endl;
    }
};
class Bill : public cuisine_details, public Delivery
{
    public:
    int pay_method;
    double amount1, amount, discount;
    void calc_bill_cust()
    {
        rate_cust = 0;
        if (event_choice == 1)
        {
            rate_cust = ph_adult[0] * no_of_adults + ph_kid[0] * no_of_kids;
            cout<<endl<<"Total charges for adults => "<<ph_adult[0]<<" X "<<no_of_adults<<" = Rs "<<
            ph_adult[0] * no_of_adults<<endl;
            cout<<"Total charges for kids   => "<<ph_kid[0]<<" X "<<no_of_kids<<" = Rs "<<
            ph_kid[0] * no_of_kids<<endl<<endl;
        }
        else if (event_choice == 2)
        {
            rate_cust = ph_adult[1] * no_of_adults + ph_kid[1] * no_of_kids;
            cout<<endl<<"Total charges for adults => "<<ph_adult[1]<<" X "<<no_of_adults<<" = Rs "<<
            ph_adult[1] * no_of_adults<<endl;
            cout<<"Total charges for kids   => "<<ph_kid[1]<<" X "<<no_of_kids<<" = Rs "<<
            ph_kid[1] * no_of_kids<<endl<<endl;
        }
        else if (event_choice == 3)
        {
            rate_cust = ph_adult[2] * no_of_adults + ph_kid[2] * no_of_kids;
            cout<<endl<<"Total charges for adults => "<<ph_adult[2]<<" X "<<no_of_adults<<" = Rs "<<
            ph_adult[2] * no_of_adults<<endl;
            cout<<"Total charges for kids   => "<<ph_kid[2]<<" X "<<no_of_kids<<" = Rs "<<
            ph_kid[2] * no_of_kids<<endl<<endl;
        }
        else
        {
            rate_cust = ph_adult[3] * no_of_adults + ph_kid[3] * no_of_kids;
            cout<<endl<<"Total charges for adults => "<<ph_adult[3]<<" X "<<no_of_adults<<" = Rs "<<
            ph_adult[3] * no_of_adults<<endl;
            cout<<"Total charges for kids   => "<<ph_kid[3]<<" X "<<no_of_kids<<" = Rs "<<
            ph_kid[3] * no_of_kids<<endl<<endl;
        }
        amount1 = rate_cust;
    }
    void calc_bill_manual()
    {
        amount1 = 0, amount = 0;
        for (int i = 0; i < 10; i++) //beverage
        {
            amount1 = amount1 + price[0][i];
        }
        for (int i = 0; i < 5; i++) //snacks
        {
            amount1 = amount1 + price[1][i];
        }
        for (int i = 0; i < 15; i++) //meal
        {
            amount1 = amount1 + price[2][i];
        }
        for (int i = 0; i < 5; i++) //dessert
        {
            amount1 = amount1 + price[3][i];
        }
    }
    void payment()
    {
        int coup_flag;
        string couponcode;
        cout << "Please choose the method of your payment" << endl << endl;
        cout << "\t\t\t\t***** 5% Cashback on payment through Credit/Debit Cards *****" << endl;
        cout << "\t\t\t\t***** 3% Cashback on payment through Digital Wallets    *****" << endl << endl;
        cout << "Press 1 for Credit/Debit Cards" << endl;
        cout << "Press 2 for Digital Wallets" << endl;
        cout << "Press 3 for Cash" << endl;
        cin >> pay_method;
        if (pay_method == 1)
        {
            discount = 0.05 * amount1;
        }
        else if (pay_method == 2)
        {
            discount = 0.03 * amount1;
        }
        else
        {
            discount = 0;
        }
        cout << endl << "\t\t\t\t***** Get extra 5% off on using promocode *****" << endl<<endl;
        cout << "Press 1 if you have a promocode else Press 2 : ";
        cin >> coup_flag;
        if (coup_flag == 1)
        {
            getchar();
            cout << "Enter promocode : ";
            getline(cin, couponcode);
            if (couponcode == "KITTY5" || couponcode == "BIRTHDAY5" || couponcode == "ANNIVERSARY5" ||
                couponcode == "MEET5")
            {
                cout<<endl<<"\t\t\t\t\t  ***** Congratulations !!! *****"<<endl;
                cout<<"\t\t\t\t\t ***** You get a 5% discount ***** "<<endl<<endl;
                discount = discount + 0.05 * amount1;
            }
            else
            {
                cout << endl<<"Invalid promocode" << endl<<endl;
            }
        }
        amount = amount1 - discount;
    }
    void address_display()
    {
        cout << endl <<"Customer's name : " << name << endl;
        cout << "Contact number : " << ph_no << endl;
        cout << "House number : " << house_no << endl;
        cout << "Street name : " << street_name << endl;
        cout << "Pincode : " << pincode << endl;
        cout << "Landmark : " << landmark << endl;
    }
    void display_cust_info()
    {
        cout << endl << "Name : " << m_name << "\t\t\t"<< "Contact Number : " << ph_n << endl;
        cout << "Date : " << date << "\t\t\t"<< "Day : " << day << endl << endl;
    }
    void final_bill_home_delivery()
    {
        if (delivery_choice == 2)
        {
            delivery_charge = 0.03 * amount1;
            amount = amount + delivery_charge;
        }
        else if (delivery_choice == 3)
        {
            delivery_charge = 0.05 * amount1;
            amount = amount + delivery_charge;
        }
        else
        {
            delivery_charge = 0;
        }
        cout << endl <<"Your total amount = Rs " << amount1 << endl;
        cout << "Your delivery charge = Rs " << delivery_charge << endl;
        cout << "Your discount amount = Rs " << discount << endl;
        cout << "Your outstanding amount = Rs " << amount << endl<<endl;
        cout << "Hope you enjoyed the food!" << endl<<endl;
    }
    void final_bill_display()
    {
        cout << endl << "Your total amount = Rs " << amount1 << endl;
        cout << "Your discount amount = Rs " << discount << endl;
        cout << "Your outstanding amount = Rs " << amount << endl<<endl;
        cout << "Hope you enjoyed the food!" << endl<<endl;
    }
    void dine_in_records()
    {
        cout<<"The Bill info as obtained from records\n"<<endl;
        final_bill_display();
    }
    void delivery_records()
    {
        cout<<"The Bill info  as obtained from records\n"<<endl;
        final_bill_display();
    }
};
class Feedback
{
    public:
    string name;
    int hygiene_rating;
    int food_rating;
    int int_decor_rating;
    int overall_rating;
    void input_feedback()
    {
        cout << endl<< "Please rate us between 1 to 10 for the following" << endl;
        cout << "Please rate for the Hygiene : ";
        cin >> hygiene_rating;
        cout << "Please rate for our Food Quality : ";
        cin >> food_rating;
        cout << "Please rate for the Decoration & Interiors : ";
        cin >> int_decor_rating;
        cout << "Please rate for the Overall Experience of the Kiosk : ";
        cin >> overall_rating;
        cout << endl<< "Thank You for giving your precious time" << endl << endl;
    }
    void display_feedback()
    {
        cout << "Category\t\t\t"<< "Rating" << endl;
        cout << "Hygiene\t\t\t\t" << hygiene_rating << endl;
        cout << "Food Quality\t\t\t" << food_rating << endl;
        cout << "Decoration & Interiors\t\t" << int_decor_rating << endl;
        cout << "Overall Experience\t\t" << overall_rating << endl << endl;
    }
};
void line()//to print <----->
{
    cout<<"<---------------------------------------------------------------------";
    cout<<"---------------------------------------------->";
    cout<<"<---------------------------------------------------------------------";
    cout<<"---------------------------------------------->";
}
int main(int argc, char const *argv[])
{
    ifstream fin;
    ofstream fout;
    int dine_choice, x, y,rec_choice,flag=0; //x=customized menu choice,y=customized menu ot not;
    long long phn;
    cout << endl;
    cout << "\t\t\t\t********** Welcome to JAYPEE Resturaunt **********" << endl;
    cout << "Please choose from the options below!" << endl;
    cout << "Press 1 for Dine-in" << endl;
    cout << "Press 2 for Home Delivery" << endl;
    cout << "Press 3 for viewing Record of Bills" << endl;
    cin >> dine_choice;
    try
    {
        if (!(dine_choice == 1 || dine_choice == 2||dine_choice == 3))
        {
            throw 0;
        }
    }
    catch (int e)
    {
        cout << "Invalid Choice" << endl;
        exit(0);
    }
    line();
    Bill b1,b2;
    b1.vector_intialization();
    if(dine_choice==3)
    {
      cout<<"Please enter the phone number to search record : ";
      cin>>phn;
      cout<<endl<<"Press 1 for Dine-in Bills, 2 for Home Delivery Bills : ";
      cin>>rec_choice;
      line();
      if(rec_choice==1)
      {
        fin.open("Dinein.txt",ios::in|ios::binary);
        fin.read((char*)&b2,sizeof(b2));
        while(!fin.eof())
        {         
             if(b2.ph_n==phn)
          {
            flag++;
            b2.dine_in_records();
          }
          fin.read((char*)&b2,sizeof(b2));
        }
      }
      else
      {
        fin.open("Delivery.txt",ios::in|ios::binary);
        fin.read((char*)&b2,sizeof(b2));
        while(!fin.eof())
        {
          if(b2.ph_no==phn)
          {
            flag++;
            b2.delivery_records();
          }
          fin.read((char*)&b2,sizeof(b2));
        }
      }
      if(flag==0)
      {
        cout<<"No record found for contact number : "<<phn<<endl<<endl; 
      }
    }
    else if (dine_choice == 1)
    {
        b1.input_customer_details();
        cout << endl;
        line();
        b1.input_event_choice();
        line();
        int x = b1.event_check();
        if (x == 1) ///customized menu
        {
            line();
            y = b1.display_customized_menu();
            line();
            if (y == 1) //agreed with customized menu
            {
                b1.cust_choice_menu();
                b1.calc_bill_cust();
            }
            else //asking for normal menu
            {
                int rep; //if repeat
                do
                {
                    b1.input_menu();
                    line();
                    b1.display_manual_menu();
                    cout << endl<<"Do you want to add-on more categories ? " << endl;
                    cout << "Press 1 for YES, 2 for NO : ";
                    cin >> rep;
                } while (rep == 1);
                line();
                b1.manual_choice_menu();
                line();
                b1.calc_bill_manual();
            }
        }
        else //normal menu
        {
            int rep; //if repeat
            line();
            do
            {
                b1.input_menu();
                line();
                b1.display_manual_menu();
                cout << endl<<"Do you want to add-on more categories ? " << endl;
                cout << "Press 1 for YES, 2 for NO : ";
                cin >> rep;
            } while (rep == 1);
            b1.manual_choice_menu();
           line();
            b1.calc_bill_manual();
        }
        b1.payment();
        line();
        b1.display_cust_info();
        line();
        b1.final_bill_display();
        fout.open("Dinein.txt",ios::app);
        if(fout)
        {
            fout.write((char*)&b1,sizeof(b1));
            cout<<"Record saved sucessfully"<<endl<<endl;
        }    
        else
        {
            cout<<"Record saving unsucessful"<<endl<<endl;
        }
        Feedback f1;
        int ask;
        cout << "Would you like to spare few minutes and provide us a feedback ? " <<endl;
        cout << "Press 1 for YES , 2 for NO : ";
        cin >> ask;//check whether wants to give feedback
        if(ask==1)
        {
         f1.input_feedback();
         f1.display_feedback();
        }
        line();
    }
    else //Home Delivery
    {
        b1.input_delivery_address();
        int rep; //if repeat
        line();
        do
        {
            b1.input_menu();
            b1.display_manual_menu();
            cout <<endl<< "Do you want to add-on more categories ? " << endl;
            cout << "Press 1 for YES, 2 for NO : ";
            cin >> rep;
        } while (rep == 1);
        b1.manual_choice_menu();
        line();
        b1.delivery_speed();
        b1.calc_bill_manual();
        b1.payment();
        line();
        b1.address_display();
        line();
        b1.final_bill_home_delivery();
        fout.open("Delivery.txt",ios::app);
        if(fout)
        {
            fout.write((char*)&b1,sizeof(b1));
            cout<<"Record saved sucessfully"<<endl<<endl;
        }    
        else
        {
            cout<<"Record saving unsucessful"<<endl<<endl;
        }
        Feedback f1;
        int ask;
        cout << "Would you like to spare few minutes and provide us a feedback ? " <<endl;
        cout << "Press 1 for YES , 2 for NO : ";
        cin >> ask;//check whether wants to give feedback
        if(ask==1)
        {
         f1.input_feedback();
         f1.display_feedback();
        }
         line();
    }
    line();
    system("pause");
    return 0;
}