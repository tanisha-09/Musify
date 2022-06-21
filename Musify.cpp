#include<bits/stdc++.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

int arr[12],i,j;
long long mob,b;
string name,gid="",sub="",mid,mpass,a;
char c;
queue<int> q;

struct node
{
    int data;
    node* left;
    node* right;
};

struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
};

Node*nnode,*current,*start=NULL;

void playSong(int p)
{
    if(p==1)
        PlaySound(TEXT("Jugnu.wav"),NULL,SND_SYNC);
    else if(p==2)
        PlaySound(TEXT("Genda Phool.wav"),NULL,SND_SYNC);
    else if(p==3)
        PlaySound(TEXT("Love Dose.wav"),NULL,SND_SYNC);
    else if(p==4)
        PlaySound(TEXT("Blue Eyes.wav"),NULL,SND_SYNC);
    else if(p==5)
        PlaySound(TEXT("Lehanga.wav"),NULL,SND_SYNC);
    else if(p==6)
        PlaySound(TEXT("No Competition.wav"),NULL,SND_SYNC);
    else if(p==7)
        PlaySound(TEXT("Tu Aake Dekhle.wav"),NULL,SND_SYNC);
    else if(p==8)
        PlaySound(TEXT("Tera Hua Na Kabhi.wav"),NULL,SND_SYNC);
    else if(p==9)
        PlaySound(TEXT("Mile Ho Tum.wav"),NULL,SND_SYNC);
    else if(p==10)
        PlaySound(TEXT("Manali Trance.wav"),NULL,SND_SYNC);
    else if(p==11)
        PlaySound(TEXT("Phir Bhi Tumko Chahunga.wav"),NULL,SND_SYNC);
    else if(p==12)
        PlaySound(TEXT("Tum Hi Ho.wav"),NULL,SND_SYNC);
    else
        cout<<"No song found."<<endl;
}
void display(int key,int j)
{
    if(key==1)
        cout<<j<<") JUGNU - BADSHAH"<<endl;
    if(key==2)
        cout<<j<<") GENDA PHOOL - BADSHAH"<<endl;
    if(key==3)
        cout<<j<<") LOVE DOSE - YO YO HONEY SINGH"<<endl;
    if(key==4)
        cout<<j<<") BLUE EYES - YO YO HONEY SINGH"<<endl;
    if(key==5)
        cout<<j<<") LEHNGA - JASS MANAK"<<endl;
    if(key==6)
        cout<<j<<") NO COMPETITION - JASS MANAK"<<endl;
    if(key==7)
        cout<<j<<") TU AAKE DEKHLE - KING"<<endl;
    if(key==8)
        cout<<j<<") TERA HUA NA MAI KABHI - KING"<<endl;
    if(key==9)
        cout<<j<<") MILE HO TUM HUMKO - NEHA KAKKAR"<<endl;
    if(key==10)
        cout<<j<<") MANALI TRANCE - NEHA KAKKAR"<<endl;
    if(key==11)
        cout<<j<<") PHIR BHI TUMKO CHAHUNGA - ARIJIT SINGH"<<endl;
    if(key==12)
        cout<<j<<") TUM HI HO - ARIJIT SINGH"<<endl;
}

void showq(queue<int> q)
{
    queue<int> g = q;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

node* search(node* root,int key)
{
    node* temp;
    if(root==NULL)
        return root;
    if(root->data>key)
        root->left=search(root->left,key);
    else if(root->data==key)
    {
        cout<<"Song found"<<endl;
        return root;
    }
    else
        root->right=search(root->right,key);

}
int totalSongs(Node* start)
{
    int total=0;
    Node* temp=new Node;
    temp=start;
    while(temp!=NULL)
    {
        total=total+1;
        temp=temp->next;
    }
    cout<<"\n\n";
    return total;
}

void printPlayList(Node* start)
{
    int j=0;
    Node* temp=new Node;
    temp=start;
    while(temp!=NULL)
    {
        j++;
        display(temp->key,j);
        temp=temp->next;
    }
    cout<<"\n\n";
}

Node* deletemenu(Node* start,int del)
{
    if(del>12)
    {
        cout<<"SONG DOESN'T EXISTS IN PLAYLIST"<<endl;
        return start;
    }
    Node* temp,*temp1,*temp2;
    if(start==NULL)
    {
        cout<<"Playlist empty"<<endl;
        return start;
    }
    else if(start->key==del && start->next==NULL && start->prev==NULL)
    {
        start=NULL;
        cout<<"SONG DELETED"<<endl;
        return start;
    }
    else if(start->key==del && start->next!=NULL)
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
        temp->next=NULL;
        delete temp;
        cout<<"SONG DELETED"<<endl;
        return start;
    }
    else
    {
        temp=start->next;
        while(temp!=NULL)
        {
            if(temp->key==del)
            {
                if(temp->next==NULL)
                {
                    temp1=temp->prev;
                    temp->prev=NULL;
                    temp1->next=NULL;
                    delete temp;
                }
                else
                {
                    temp1=temp->prev;
                    temp2=temp->next;
                    temp->next=NULL;
                    temp->prev=NULL;
                    temp1->next=temp2;
                    temp2->prev=temp1;
                    delete temp;
                    cout<<"SONG DELETED"<<endl;
                    return start;
                }
            }
            else
                temp=temp->next;
        }
        cout<<"SONG DOESN'T EXISTS IN PLAYLIST"<<endl;
        return start;
    }
}

Node* addNode(Node* start)
{
    nnode=new Node;
    cout<<"Enter your choice:\t";
    cin>>nnode->key;
    nnode->next=NULL;
    nnode->prev=NULL;
    if(start==NULL)
    {
        current=nnode;
        start=nnode;
    }
    else
    {
        current->next=nnode;
        nnode->prev=current;
        current=nnode;
    }
    cout<<"SONG SUCCESSFULLY ADDED."<<endl;
    return start;
}

void lists()
{
    cout<<"\t\t\t************THESE ARE THE LATEST HITS YOU CAN ADD IN YOUR PLAYLIST***********"<<endl;
    cout<<"1.  JUGNU - BADSHAH"<<endl;
    cout<<"2.  GENDA PHOOL - BADSHAH"<<endl;
    cout<<"3.  LOVE DOSE - YO YO HONEY SINGH"<<endl;
    cout<<"4.  BLUE EYES - YO YO HONEY SINGH"<<endl;
    cout<<"5.  LEHANGA - JASS MANAK"<<endl;
    cout<<"6.  COMPETITION - JASS MANAK"<<endl;
    cout<<"7.  TU AAKE DEKHLE - KING"<<endl;
    cout<<"8.  TERA HUA NA MAI KABHI - KING"<<endl;
    cout<<"9.  MILE HO TUM HUMKO - NEHA KAKKAR"<<endl;
    cout<<"10. MANALI TRANCE - NEHA KAKKAR"<<endl;
    cout<<"11. PHIR BHI TUMKO CHAHUNGA - ARIJIT SINGH"<<endl;
    cout<<"12. TUM HI HO - ARIJIT SINGH"<<endl;
}
void favPlaylist(int arr[12])
{
    int f=0;
    cout<<"Your favourite songs are : "<<endl<<endl;
    for(i=0; i<12; i++)
    {
        if(arr[i]==1)
            cout<<"JUGNU - BADSHAH"<<endl;
        else if(arr[i]==2)
            cout<<"GENDA PHOOL - BADSHAH"<<endl;
        else if(arr[i]==3)
            cout<<"LOVE DOSE - YO YO HONEY SINGH"<<endl;
        else if(arr[i]==4)
            cout<<"BLUE EYES - YO YO HONEY SINGH"<<endl;
        else if(arr[i]==5)
            cout<<"LEHANGA - JASS MANAK"<<endl;
        else if(arr[i]==6)
            cout<<"COMPETITION - JASS MANAK"<<endl;
        else if(arr[i]==7)
            cout<<"TU AAKE DEKHLE - KING"<<endl;
        else if(arr[i]==8)
            cout<<"TERA HUA NA MAI KABHI - KING"<<endl;
        else if(arr[i]==9)
            cout<<"MILE HO TUM HUMKO - NEHA KAKKAR"<<endl;
        else if(arr[i]==10)
            cout<<"MANALI TRANCE - NEHA KAKKAR"<<endl;
        else if(arr[i]==11)
            cout<<"PHIR BHI TUMKO CHAHUNGA - ARIJIT SINGH"<<endl;
        else if(arr[i]==12)
            cout<<"TUM HI HO - ARIJIT SINGH"<<endl;
        else;
    }
    for(i=0; i<12; i++)
    {
        if(arr[i]!=0)
        {
            f=f+1;
        }
    }
    if(f==0)
    {
        cout<<"Empty Favourite Artist's Playlist"<<endl<<endl;
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        display(root->data,root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        display(root->data,root->data);
    }
}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        display(root->data,root->data);
        inorder(root->right);
    }
}

node * n_node,*root=NULL;
node* insert(node* root,int key)
{
    n_node=new node;
    n_node->data=key;
    n_node->left=NULL;
    n_node->right=NULL;
    if(root==NULL)
    {
        root=n_node;
    }
    else
    {
        if(n_node->data<root->data)
        {
            if(root->left==NULL)
                root->left=n_node;
            else
                insert(root->left,n_node->data);
        }
        else
        {
            if(root->right==NULL)
                root->right=n_node;
            else
                insert(root->right,n_node->data);
        }
    }
    return root;
}

void load(int a)
{
    int v;
    for(int h=0; h<a; h++)
    {
        v=0;
    }
}
void loading()
{
    cout<<"LOADING";
    for(int j=0; j<21; j++)
    {
        load(9999999);
        cout<<" .";
    }
    cout<<"\n";
    system("cls");
}

void artists()
{
    loading();
    cout<<"\t\t\t\t***** WELCOME TO ARTISTS SECTION *****"<<endl<<endl;
    cout<<"\t\t *****HERE YOU CAN CHOOSE YOUR FAVOURITE ARTISTS AND THEIR SONGS *****"<<endl<<endl;
    cout<<"\tENTER 'SKIP' TO SKIP, ANY OTHER KEY TO CONTINUE : \t";
    cin>>a;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    if(a=="skip")
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t\tWELCOME TO MUSIFY     "<<endl;
        cout<<"\t\t\t\t**************************************"<<endl<<endl<<endl;
    }
    else
    {
        cout<<"\nSELECT YOUR FAVOURITE ARTIST (1 at a time) FROM THE FAMOUS ARTISTS!!"<<endl<<endl;
        cout<<"\n1. BADSHAH - Most Viewed Song <<Genda Phool>>\n\n2. YO YO HONEY SINGH - Most Viewed Song <<Dheere Dheere>>"<<endl;
        cout<<"\n3. JASS MANAK - Most Viewed Song <<Lehnga>>\n\n4. KING - Most Viewed Song <<Tu Aake Dekhle>>"<<endl;
        cout<<"\n5. NEHA KAKKAR - Most Viewed Song <<Mile Ho Tum Humko>>\n\n6.ARIJIT SINGH - Most Viewed Song <<Phir Bhi Tumko Chahunga>>"<<endl<<endl;
        cout<<"Enter your choice - \t";
        cin>>a;
        if(a=="1")
        {
            arr[0]=1;
            arr[1]=2;
        }
        else if(a=="2")
        {
            arr[2]=3;
            arr[3]=4;
        }
        else if(a=="3")
        {
            arr[4]=5;
            arr[5]=6;
        }
        else if(a=="4")
        {
            arr[6]=7;
            arr[7]=8;
        }
        else if(a=="5")
        {
            arr[8]=9;
            arr[9]=10;
        }
        else if(a=="6")
        {
            arr[10]=11;
            arr[11]=12;
        }
        else
            cout<<"Wrong choice."<<endl;
    }
    loading();
    favPlaylist(arr);
}

void googleSignUps()
{
    loading();
    cout<<"Enter your gmail id :\t";
    fflush(stdin);
    getline(cin,gid);
    b=gid.size();
    if(b<10)
    {
        cout<<"Invalid gmail id.... Gmail id always ends with @gmail.com!!"<<endl;
        cout<<"Reloading the Google Signup Page."<<endl<<endl;
        cout<<"\t\t\t<<PRESS ANY KEY TO CONTINUE>>"<<endl;
        cin>>c;
        googleSignUps();
    }
    else
    {
        sub=gid.substr(b-10,b);
        if(sub!="@gmail.com")
        {
            cout<<"Invalid gmail id.... Gmail id always ends with @gmail.com!!"<<endl;
            cout<<"Reloading the Google Signup Page."<<endl<<endl;
            cout<<"\t\t\t<<PRESS ANY KEY TO CONTINUE>>"<<endl;
            cin>>c;
            googleSignUps();
        }
        else
        {
            cout<<"Enter password :\t";
            cin>>mpass;
            cout<<"Creating account!!!!";
            for(int j=0; j<21; j++)
            {
                load(9999999);
                cout<<" .";
            }
            cout<<"\nAccount created successfully!!"<<endl;
            cout<<"\nEnter any key to continue."<<endl;
            cin>>a;
        }
    }
}

void musifySignUps()
{
    loading();
    cout<<"\t\t\t\t**************************************"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO MUSIFY SIGNUPS     "<<endl;
    cout<<"\t\t\t\t**************************************"<<endl<<endl<<endl;
    cout<<"\nEnter your name :\t";
    fflush(stdin);
    getline(cin,name);
    cout<<"\nEnter your mobile number :\t";
    cin>>mob;

    cout<<"\nEnter any key to generate your UNIQUE MUSIFY ID by MUSIFY itself."<<endl;
    cin>>a;
    cout<<"LOADING";
    for(int j=0; j<21; j++)
    {
        load(9999999);
        cout<<" .";
    }
    cout<<"\n";
    cout<<"Your UNIQUE MUSIFY ID is : 'AZS41000'. Remember this for future logins."<<endl;
    cout<<"Your UNIQUE password is same as your UNIQUE MUSIFY ID."<<endl;
    cout<<"Creating account!!!!";
    for(int j=0; j<21; j++)
    {
        load(9999999);
        cout<<" .";
    }
    cout<<"\nAccount created successfully!!"<<endl;
    cout<<"\nEnter any key to continue."<<endl;
    fflush(stdin);
    cin>>a;
}

void signup()
{
    loading();
    cout<<"\t\t\t\t***********************************"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO SIGNUP PAGE     "<<endl;
    cout<<"\t\t\t\t***********************************"<<endl<<endl;
    cout<<"\t\t\t\t<<<<<<<<<<  SIGNUP NOW  >>>>>>>>>>>"<<endl<<endl;
    cout<<"Listen to all your favourite songs for free on Musify."<<endl<<endl;
    cout<<"Press 1 for 'MUSIFY SIGNUPS'"<<endl;
    cout<<"           OR               "<<endl;
    cout<<"Press any other key to sign up with Google Account"<<endl;
    cin>>a;
    if(a=="1")
        musifySignUps();
    else
        googleSignUps();
}
void login()
{
    cout<<"Enter your Musify I'd :\t\t";
    cin>>mid;
    b=mid.size();
    if(b<=3)
    {
        cout<<"\n\t'"<<mid<<"' is not a valid Musify I'd!!"<<endl;
        cout<<"\tMusify Id always ends with '000'"<<endl;
        cout<<"\tTry to LOGIN AGAIN...."<<endl<<endl;
        login();
    }
    else
    {
        sub=mid.substr(b-3,b);
        if(sub=="000")
        {
            cout<<"Enter password for your musify ID :\t";
            fflush(stdin);
            getline(cin,mpass);
            if(mid==mpass)
            {
                loading();
            }
            else
            {
                cout<<"WRONG PASSWORD.... "<<endl<<endl;
                cout<<"If you forgot your password you can create a new account for free...."<<endl<<endl;
                cout<<"Press 1 to login again."<<endl;
                cout<<"Press 2 for signing up for a new account."<<endl;
                cin>>a;
                if(a=="1")
                    login();
                else if(a=="2")
                    signup();
                else
                {
                    cout<<"Invalid choice...."<<endl;
                    cout<<"Returning to login page again...."<<endl;
                    cout<<"<<Press any key to continue>>"<<endl;
                    cin>>a;
                    login();
                }
            }
        }
        else
        {
            cout<<"\n\t'"<<mid<<"' is not a valid Musify I'd!!"<<endl;
            cout<<"\tMusify Id always ends with '000'"<<endl;
            cout<<"\tTry to LOGIN AGAIN...."<<endl<<endl;
            login();
        }
    }
}

int main()
{
    for(int i=0; i<12; i++)
    {
        arr[i]=0;
    }
    cout<<"LOADING";
    for(int j=0; j<21; j++)
    {
        load(9999999);
        cout<<" .";
    }
    cout<<"\n";
    system("cls");
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,11);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,9);
    root=insert(root,5);
    root=insert(root,10);
    cout<<"\t\t\t\t***********************************"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO LOGIN PAGE     "<<endl;
    cout<<"\t\t\t\t***********************************"<<endl<<endl<<endl;
    login();
    artists();

    int c,d,p,total=0;
    char choice;
    string strin;
    cout<<"\t\t\t\t**************************************"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO MUSIFY     "<<endl;
    cout<<"\t\t\t\t**************************************"<<endl<<endl<<endl;
    cout<<"Listen to all your favourite songs for free on Musify."<<endl<<endl;
    cout<<"\n\nEnter your playlist name-  ";
    fflush(stdin);
    getline(cin,strin);
    do
    {
        cout<<"\n(a)Add new song in your playlist.\n(b)Delete Song from your Playlist.\n(c)Display Entered Playlist.\n(d)Total Songs in playlist.\n(e)Shuffle1.\n(f)Shuffle2.\n(g)Shuffle3.\n(h)Search.\n(i)Recently Searched Songs.\n(j)Play Any Song.\n(k)Favourite Artist's Songs.\n(l)Exit.\n"<<endl;
        cout<<("\nEnter your choice- ");
        cin>>choice;

        switch(choice)
        {
        case 'a':
            lists();
            start=addNode(start);
            break;
        case 'b':
            cout<<"Enter the number of song to be deleted"<<endl;
            fflush(stdin);
            cin>>c;
            start=deletemenu(start,c);
            break;
        case 'c':
            printPlayList(start);
            break;
        case 'd':
            total=totalSongs(start);
            cout<<total<<endl<<endl;
            break;
        case 'e':
            preorder(root);
            break;
        case 'f':
            postorder(root);
            break;
        case 'g':
            inorder(root);
            break;
        case 'h':
            lists();
            cout<<"Enter the song to be searched :\t";
            cin>>d;
            q.push(d);
            root=search(root,d);
            break;
        case 'i':
            showq(q);
            break;
        case 'j':
            lists();
            cout<<"Enter song to be played for you:\t";
            cin>>p;
            playSong(p);
            break;
        case 'k':
            favPlaylist(arr);
            break;
        case 'l':
            exit(0);
        }
    }
    while(choice!='z');
    return 0;
}
