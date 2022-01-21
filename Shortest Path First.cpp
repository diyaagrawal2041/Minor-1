#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<map>
#include<time.h>
#define V 27
using namespace std;
map<int, string> mapping;
int graph[V][V] = { { 0,4.2,26.1,0,0,0,0,0,0,0,0,0,3.8,0,0,5,0,0,0,0,0,0,0,0,0,0,0 },
                        { 4.2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11.3,0,0,0,0,0,0,0,0,0,0 },
                        { 26.1,0,0,0,0,0,0,0,0,0,18.6,0,0,0,0,0,4.8,0,0,0,0,0,0,0,0,0,0 },
                        { 0,0,0,0,0,0,0,0,0,0,0,0,10.3,0,0,0,5.5,0,9.4,0,0,5.4,0,0,0,0,0 },
                        { 0,0,0,0,0,0,0,0,0,0,0,0,5.3,10,0,5.9,0,0,0,0,0,0,4.6,0,2.6,0,0 },
                        { 0,0,0,0,0,0,0,0,6.7,0,0,0,0,15.1,10.1,0,0,0,0,0,0,0,0,0,6.1,12.7,0 },
                        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,16.3,0,0,0,0,0,0,0 },
                        { 0,0,0,0,0,0,0,0,0,0,0,2.3,0,0,0,0,0,0,0,0,0,9.4,6.8,1.4,0,0,0 },
                        { 0,0,0,0,0,6,0,0,0,19.2,0,0,0,0,6.4,0,0,0,0,0,0,0,0,0,0,12.5,0 },
                        { 0,0,0,0,0,0,0,0,19.2,0,0,0,0,0,0,0,0,0,0,0,0,0,21.2,19.3,0,0,0 },
                        { 0,0,18.6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2.1,0,0,0,0,0,0,0,0,18.2 },
                        { 0,0,0,0,0,0,0,2.3,0,0,0,0,0,0,0,0,0,0,6.6,16.9,3,9.3,0,0,0,0,0 },
                        { 3.8,0,0,10.3,5.3,0,0,0,0,0,0,0,0,0,0,6.5,0,0,0,0,0,10,2.7,0,0,0,0 },
                        { 0,0,0,0,10,15.1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17.4,0 },
                        { 0,0,0,0,0,10.1,0,0,6.4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7.2,0,0 },
                        { 5,0,0,0,5.9,0,0,0,0,0,0,0,2.4,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                        { 0,5.5,11.3,5.5,0,0,0,0,0,0,0,0,0,0,0,0,0,16.6,6.8,0,0,0,0,0,0,0,0 },
                        { 0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,16.6,0,10.2,0,0,0,0,0,0,0,0 },
                        { 0,0,0,9.4,0,0,5,0,0,0,0,6.6,0,0,0,0,6.8,10.2,0,19.6,0,0,0,0,0,0,0 },
                        { 0,0,0,0,0,0,16.3,0,0,0,0,16.9,0,0,0,0,0,0,19.6,0,0,0,0,0,0,0,12 },
                        { 0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1.6,0,0,9.7 },
                        { 0,0,0,5.4,0,0,0,9.4,0,0,0,9.3,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                        { 0,0,0,0,4.6,0,0,6.8,0,21.2,0,0,2.7,0,0,0,0,0,0,0,0,0,0,0,4.7,0,0 },
                        { 0,0,0,0,0,0,0,1.4,0,19.3,0,0,0,0,0,0,0,0,0,0,1.6,0,0,0,0,0,0 },
                        { 0,0,0,0,2.6,6.1,0,0,0,0,0,0,0,0,7.2,0,0,0,0,0,0,0,4.7,0,0,0,0 },
                        { 0,0,0,0,0,12.7,0,0,12.5,0,0,0,0,17.4,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                        { 0,0,0,0,0,0,0,0,0,0,18.2,0,0,0,0,0,0,0,0,13.3,9.1,0,0,0,0,0,0 }};
                        

class Path
{
	public:
		map<int,int> sort(map<int, int>& M)
		{
		    multimap<int, int> MM;
		    map<int,int> sort1;
		    map<int, int>::iterator itr1;
		    multimap<int, int>::iterator it;
		    for (itr1 = M.begin(); itr1 != M.end(); ++itr1) {
		        MM.insert({ itr1->second, itr1->first });
		    }
		    for (it = MM.begin(); it != MM.end(); ++it) {
		    	sort1.insert(pair<int, int>(it->first, it->second));
		    }
		    return sort1;
		}
		
		string convertToString(char* a, int size)
		{
		    string s = a;
		    return s;
		}
		
		void printPath(int parent[], int j)
		{
		       
		    if (parent[j] == - 1)
		        return;
		   
		    printPath(parent, parent[j]);
		   	map<int, string>::iterator m1;
		   	m1 = mapping.find(j);
		    cout<<" -> "<<m1->second;
		}
		
		void printSolution(int initial, int parent[], int final)
		{
			map<int, string>::iterator m1;
		    int src = initial;
		    m1 = mapping.find(src);
		    cout<<"\n"<<"The path followed by the delivery person is: "<<m1->second;
		    printPath(parent, final);
		    cout<<"\n";
		}
		
		int minDistance(int dist[], bool sptSet[])
		{
		    int min = INT_MAX, min_index;
		    for (int v = 0; v < V; v++)
		        if (sptSet[v] == false && dist[v] <= min)
		            min = dist[v], min_index = v;
		    return min_index;
		}
		
		void printWithPath(int graph[V][V], int src, int dest)
		{
		    int dist[V]; 
		    bool sptSet[V];
		    int parent[V];
		    for (int i = 0; i < V; i++)
		    {
		        parent[src] = -1;
		        dist[i] = INT_MAX;
		        sptSet[i] = false;
		    }
		    dist[src] = 0;
		   
		    for (int count = 0; count < V - 1; count++)
		    {
		       
		        int u = minDistance(dist, sptSet);
		   
		        
		        sptSet[u] = true;
		   
		        for (int v = 0; v < V; v++)
		   
		            
		            if (!sptSet[v] && graph[u][v] &&
		                dist[u] + graph[u][v] < dist[v])
		            {
		                parent[v] = u;
		                dist[v] = dist[u] + graph[u][v];
		            } 
		    }
		    
		    printSolution(src, parent, dest);
		}


		map<int, int> dijkstra(int graph[V][V], int src)
		{
		    int dist[V]; 
		    bool sptSet[V]; 
		    for (int i = 0; i < V; i++)
		        dist[i] = INT_MAX, sptSet[i] = false;
		    dist[src] = 0;
		    for (int count = 0; count < V - 1; count++) {
		        int u = minDistance(dist, sptSet);
		        sptSet[u] = true;
		        for (int v = 0; v < V; v++)
		            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
		                && dist[u] + graph[u][v] < dist[v])
		                dist[v] = dist[u] + graph[u][v];
		    }
		    map<int,int> values;
		    map<int,int>::iterator itr;
		    
		    for (int i = 0; i < V; i++)
        		values.insert(pair<int, int>(i, dist[i]));
        		
        	values = sort(values);
        	map<int, int> res;
        	for (itr = values.begin(); itr != values.end(); ++itr) {
        		if(itr->second < 10)
        		{
        			res.insert(pair<int, int>(itr->first, itr->second));
				}
        	}
        	return res;
		}
};
class Sign
{
    protected:
        char username[50];
        char password[50];
    public:
        void Register()
        {
            ofstream fs("logindataset.txt",ios::app);   
            cout<<"Enter username: ";
            cin>>username;
            cout<<"Enter password: ";
            cin>>password;
            fs<<username<<" "<<password<<" ";   
            cout<<"User Registered !";
            fs.close();
        }
        void login(char  un[],char pw[])
        {
            ifstream fs("logindataset.txt",ios::in);
            while(!fs.eof())
            {
                fs>>username>>password;   
                if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
                {
                    cout<<"WELCOME: "<<username;
                    break;
                }
                /*else{
					
                    	cout<<"Sorry ! Invalid Credentials";
                    	break;
					}*/
                    
           
            }
            fs.close();   
        }
        void restaurant(){
			ifstream f; f.open("restlist.txt");
            if ( f.is_open() ) {
				char list;
				while ( f ) {
					list = f.get();
					cout << list;
				}
			}
		}
		void menu(){
			ifstream q1; q1.open("menu2.txt");
            if ( q1.is_open() ) {
				char list1;
				while ( q1 ) {
					list1 = q1.get();
				}
			}
		}
		void foodmenu()
		{
			cout<<"\n\n\n\t\t\t\t\t FOOD MENU "<<endl;
			cout<<"\n\t\t"; 
			cout<<"______ ";
			cout<<"\n\n\t\t"; 
			cout<<"|  Sr. No.  |   Food Name         |  Price     | ";
			cout<<"\n\t\t";
			cout<<"______ ";
			cout<<"\n\t\t";
			cout<<"\t\n               |     01     |    MOMOS            |   60.00   | ";
			cout<<"\t\n               |     02     |    BURGER           |   40.00   | ";
			cout<<"\t\n               |     03     |    PIZZA            |   200.00  | ";
			cout<<"\t\n               |     04     |    RED SAUCE PASTA  |   220.00  | ";
			cout<<"\t\n               |     05     |    FRIED RICE       |   90.00   | ";
			cout<<"\t\n               |     06     |    SAUSAGE          |   250.00  | ";
			cout<<"\t\n               |     07     |    CAKE             |   400.00  | ";
			cout<<"\t\n               |     08     |    BIRYANI          |   80.00   | ";
			cout<<"\t\n               |     09     |    CHILLY POTATO    |   50.00   | ";
			cout<<"\t\n               |     10     |    INDIAN THALI     |   100.00  | ";
			cout<<"\n\n\t\t------------------------------------------------------";
			cout<<"\n\t\t"; 
		}
		
};
int main()
{
   
    Sign l1;
    Path p1;
    while(1)
    {
    system("cls");
    char username[50],password[50];
    int ch1,ch2,ch3,ch4,ch6,ch7;
    int cost=0,fcost=0;
    int i=0,j=0;
    char dp[30],rp[50],mt[50],as[50],ch5;
    char num[12],ed[10],name[20],cvv[4],upiid[20];
    
    mapping.insert(pair<int, string>(0,"Ego Thai"));
    mapping.insert(pair<int, string>(1,"Fio Country Kitchen Bar"));
    mapping.insert(pair<int, string>(2,"Big Yellow Door"));
    mapping.insert(pair<int, string>(3,"Lights, Camera, Action"));
    mapping.insert(pair<int, string>(4,"Garage Inc"));
    mapping.insert(pair<int, string>(5,"Lodi"));
    mapping.insert(pair<int, string>(6,"Rajinder Da Dhaba"));
    mapping.insert(pair<int, string>(7,"The Toddy Shop"));
    mapping.insert(pair<int, string>(8,"The Project at the Park Balluchi"));
    mapping.insert(pair<int, string>(9,"Terminus 1"));
    mapping.insert(pair<int, string>(10,"Jasola"));
    mapping.insert(pair<int, string>(11,"Hauz Khas"));
    mapping.insert(pair<int, string>(12,"Lajpat Nagar"));
    mapping.insert(pair<int, string>(13,"Vasant Kunj"));
    mapping.insert(pair<int, string>(14,"Saket"));
    mapping.insert(pair<int, string>(15,"Greater Kailash"));
    mapping.insert(pair<int, string>(16,"Chanakyapuri"));
    mapping.insert(pair<int, string>(17,"Sarita Vihar"));
    mapping.insert(pair<int, string>(18,"Defence Colony"));
    mapping.insert(pair<int, string>(19,"Raj Nagar"));
    mapping.insert(pair<int, string>(20,"Malviya Nagar"));
    mapping.insert(pair<int, string>(21,"Dhaula Kua"));
    mapping.insert(pair<int, string>(22,"South Extension"));
    mapping.insert(pair<int, string>(23,"Sarvapriya Vihar"));
    mapping.insert(pair<int, string>(24,"Safdarjung"));
    mapping.insert(pair<int, string>(25,"Okhla"));
    mapping.insert(pair<int, string>(26,"Moti Bagh"));
    

    cout<<" *  Welcome to Fastest Food Delivery System **";
    cout<<"\n\n 1. Login : Already existing customer  \n\n 2. New ? Register Now! \n\n 3. Exit"<<endl;
    cout<<"\nEnter choice: ";
    cin>>ch1;
    switch(ch1)
    {
        case 1:
           cout<<" Username : "; cin>>username;
           cout<<" Password : "; cin>>password;
           cout<<"\n";
           l1.login(username,password);
        break;
        case 2:
                l1.Register();
                cout<<"\nPlease login now ";
           cout<<"\n Username : "; cin>>username;
           cout<<" Password : "; cin>>password;
           cout<<"\n";
           l1.login(username,password);
                
        break;
        case 3:
            exit(1);
    }
   
    cout<<" \n\n ENTER DELIVERY POINT: ";
    cout<<"\n\n 1.Jasola   \n\n 2.Hauz Khas  \n\n 3.Lajpat Nagar \n\n 4.Vasant Kunj  \n\n 5.Saket \n"<<endl;
    cout<<"\nEnter choice: ";
    cin>>ch2;
    switch(ch2)
    {
        case 1: strcpy(dp, "Jasola");
        break;
        case 2:strcpy(dp, "Hauz Khas");
        break;
        case 3:strcpy(dp, "Lajpat Nagar");
        break;
        case 4:strcpy(dp, "Vasant Kunj");
        break;
        case 5:strcpy(dp, "Saket");
        break;
        default: cout<<"Enter valid location ";
        exit(1);
    }
    cout<<"\nYour order will be delivered at ";
    cout<<dp;
    cout<<"\n\nPLEASE SELECT THE RESTAURANTS FROM THE OPTIONS BELOW: \n";
    l1.restaurant();
    
    //path calculations
    map<int,int> pathdist;
    int dp_size = sizeof(dp) / sizeof(char);
    string s_dp = p1.convertToString(dp, dp_size);
    map<int, string>::iterator i11;
    int key_of_location;
    for(i11 = mapping.begin(); i11 != mapping.end(); ++i11)
    {
    	if(i11->second == s_dp)
    	{
    		key_of_location = i11->first;
		}
	}
    pathdist = p1.dijkstra(graph, key_of_location);
    map<int, int>::iterator it;
    map<int, string>::iterator it11;
    int count = 0;
    
    //Show suggestions for the restaurants which are less than 10 km away from the delivery point. It can maximum show 3 restuarants.
    cout<<"\n\nGET FAST DELIVERY FROM- ";
    for (it = pathdist.begin(); it != pathdist.end(); ++it) {
    	if(count==3)
    	{
    		break;
		}
    	int key = it->second;
    	if(it->first>10)
    	{
    		break;
		}
    	count++;
    	it11 = mapping.find(key);
    	cout<<'\n'<<it11->second<<" - "<<it->first<<"Km from your distance.";
    }
    p1.dijkstra(graph, key_of_location);
    cout<<"\n\nEnter choice: ";
    cin>>ch3;
    switch(ch3)
    {
        case 1: strcpy(rp, "Ego Thai");
        break;
        case 2:strcpy(rp, "Fio Country Kitchen Bar");
        break;
        case 3:strcpy(rp, "Big Yellow Door");
        break;
        case 4:strcpy(rp, "Lights, Camera, Action");
        break;
        case 5:strcpy(rp, "Garage Inc");
        break;
        case 6: strcpy(rp, "Lodi");
        break;
        case 7:strcpy(rp, "Rajinder Da Dhaba");
        break;
        case 8:strcpy(rp, "The Toddy Shop");
        break;
        case 9:strcpy(rp, "The Project at the Park Balluchi");
        break;
        case 10:strcpy(rp, "Terminus 1");
        break;
        default: cout<<"Choose valid restaurant ";
        exit(1);
    }
    int rp_size = sizeof(rp) / sizeof(char);
    string s_rp = p1.convertToString(rp, rp_size);
    map<int, string>::iterator i22;
    int key_of_dest;
    for(i22 = mapping.begin(); i22 != mapping.end(); ++i22)
    {
    	if(i22->second == s_rp)
    	{
    		key_of_dest = i22->first;
		}
	}
	for (it = pathdist.begin(); it != pathdist.end(); ++it) {
    	if(it->second == key_of_dest)
    	{
    		cout<<'\n'<<s_rp<<" is "<<it->first<<" KM away from your delivery point i.e. "<<s_dp<<"\n";
		}
    	
    }
	
    //Print the path of travelling
    
	p1.printWithPath(graph, key_of_dest, key_of_location);
	
    cout<<"\n Choose from the menu of ";
    cout<<rp<<":\n";
    l1.foodmenu();
    do{
	
    l1.menu();
    cout<<"\n\nEnter choice: ";
    cin>>ch4;
    switch(ch4)
    {
        case 1: strcpy(mt, "MOMOS");
        cost=60;
        break;
        case 2:strcpy(mt, "BURGER");
        cost=40;
        break;
        case 3:strcpy(mt, "PIZZA");
        cost=200;
        break;
        case 4:strcpy(mt, "RED SAUCE PASTA");
        cost=220;
        break;
        case 5:strcpy(mt, "FRIED RICE");
        cost=90;
        break;
        case 6: strcpy(mt, "SAUSAGE");
        cost=250;
        break;
        case 7:strcpy(mt, "CAKE");
        cost=400;
        break;
        case 8:strcpy(mt, "BIRYANI");
        cost=80;
        break;
        case 9:strcpy(mt, "CHILLY POTATO");
        cost=50;
        break;
        case 10:strcpy(mt, "INDIAN THALI");
        cost=100;
        break;
        default: cout<<"Invalid Choice";
        exit(1);
    
}
cout<<"\n";
cout<<mt<<" is added...";
fcost+=cost;
cout<<"\nTotal Cost of your order is: Rs."<<fcost;
cout<<"\nYour order is recorded, do you want to add more items ?(y/n): ";
cin>>ch5;
if(ch5!='y')
{
	cout<<"\nThankyou for ordering from "<<rp;
	break;
}
}while(ch5=='y');
			cout<<"\n\n Please select the mode of payment : ";
			cout<<"\n1. Debit Card -->";
			cout<<"\n2. UPI -->";
			cout<<"\n3. Cash on delivery -->";
			cout<<"\nEnter your choice: ";	
			cin>>ch6;	
			switch(ch6)
			{
				case 1: cout<<"\nPlease enter your card details";
						cout<<"\nCard Number: ";
						cin>>num;
						cout<<"\nExpiry Date: ";
						cin>>ed;
						cout<<"\nName on the card: ";
						cin>>name;
						cout<<"\nCVV: ";
						cin>>cvv;
						cout<<"\n\n Payment Successful !";
						break;
				case 2: cout<<"\nEnter UPI id: ";
						cin>>upiid;
						cout<<"\n\n Payment Successful !";
						break;
				case 3: cout<<"Please pay Rs. "<<fcost<<" to our delivery partner";
						break;
				
				default : cout<<"Payment Failed ! Please try again\n";	
						
				
				}	

_getch();
  }
  return 0;
}
