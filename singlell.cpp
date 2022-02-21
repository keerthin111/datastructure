#include<iostream.h>
# include<cstdlib>
using  namespace std;
struct node
{
  int info;
  struct node*next;
}*start;
class single_llist
{
	public:
		node*create_node(int);
		void insert_begin();
	    void insert_last();
		void insert_pos();
	    void delete_begin();
	    void delete_last();
	    void delete_pos();
	    void update_ begin();
        void update_last();
	    void update_pos();
	    void sort();
	    void search();
	    void disply();
	    single_llist()
	    {
	    	start=NULL;
		}
	
};
int main()
{
int choice;
single_llist s1,s2;
start=NULL;
do
{
	cout<<"----------------------------------"<<endl;
	cout<<"Operations on singly linked list"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"1.insert at first"<<endl;
	cout<<"2.insert at last"<<endl;
	cout<<"3.insert at position"<<endl;
	cout<<"4.delete at first"<<endl;
	cout<<"5.delete at last"<<endl;
	cout<<"6.delete at postion"<<endl;
	cout<<"7.update at first"<<endl;
	cout<<"8.update at last "<<endl;
	cout<<"9.update at  position"<<endl;
	cout<<"10.Ascending order"<<endl;
	cout<<"11.Descending order"<<endl;
	cout<<"12.Search"<<endl;
	cout<<"13.Display"<<endl;
	cout<<"14.exit"<<endl;
	cout<<"enter ur choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:s1.insert_begin();
		s1.display();
		break;
		case 2:s1.insert_last();
		s1.display();
		break;
		case 3:s1.insert_pos();
		s1.display();
		break;
		case 4:s1.delete_begin();
		s1.display();
		break;
		case 5:s1.delete_last();
		s1.display();
		break;
		case 6:s1.delete_pos();
		s1.display();
		break;
		case 7:s1.update_first();
		s1.display();
		break;
		case 8:s1.update_last();
		s1.display();
		break;
		case 9:s1.update_pos();
		s1,display();
		break;
		case 10:s1.sort();
		s1.display();
		break;
		case 11:s1.reverse();
		s1.display();
		break;
		case 12: s1.search();
		s1.display();
		break;
		case 13:s1.display();
		break;
		case 14:s1.exit();
		break;
		defauit:cout<<"Wrong choice    ????"<<endl;
		break;		
	}
} while(choice!=14);
}
node*single_llist::create_node(int value)
{
	struct node*temp,*s;
	temp=new(struct node);
	if(temp==NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return 0;
	}
	else
	{
		temp->info=value;
		temp->next=NULL;
		return temp;
	}
}
void single_llist::insert_begin()
{
	int value;
	cout<<"Enter the value to be i nserted:";
	cin>>value;
	struct node*temp,*s;
	temp=create_node(value);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
		cout<<temp->info<<"is inserted at fiest in the empty list"<<endl;
		
	}
	else
	{
		s=start;
		start=temp;
		start->next=s;
		cout<<temp->info<<"is inserted at first"<<endl;
	}
}
void single_llist::insert_last()
{
	int value;
	cout<<"enter the value to be inserted :";
	cin>>value;
	struct node*temp,*s;
	temp=create_node(value);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
		cout<<temp->info<<"is inserted at last in the empty list"<<endl;
		
	}
	else
	{
		s=start;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		temp->next=temp;
		s->next=temp;
		cout<<temp->info<<"is inserted at last"<<endl;
		
	}
}
void single_llist::insert_pos()
{
	int value,pos,counter=0,loc-1;
	struct node*temp,*s,*ptr;
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		counter++;
	}
	if(counter==0){}
	else {
		cout<<"enter the position from"<<loc<<"to"<<counter+1<<":";
		cin>>pos;
		s=start;
		if(pos==1)
		{
			cout<<"enter the value to be inserted:";
			cin>>value;
			temp=create_node(value);
			start=temp;
			start->next=s;
			cout<<temp->info<<"is inserted at first"<<endl;
		}
		else if(pos>1&&pos<=counter)
		{
			cout<<"enter the value to be inseted:";
			cin>>value;
			temp=create_node(value);
			for(int i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
				
			}
			ptr->next=temp;
			temp->next=s;
			cout<<temp->info<<"is inserted at postion"<<pos<<endl; 
		}
		else if(pos==counter+1)
		{
			cout<<"Enter the value to be inserted:";
			cin>>value;
			temp=create_node(value);
			while(s->next=null)
			{
				S=S->next;
			}
			temp->next=NULL;
			s->next=temp;
			cout<<temp->info<<"is inserted at last"<<endl;
			
		}
		else
		{
			cout<<"position out of range....!!!"<<endl;
		}
    }
}
void single_llist::delete_begin()
{
 if (start == NULL){}
 else
 {
 struct node *s, *ptr;
 s = start;
 start = s-&gt;next;
 cout&lt;&lt;s-&gt;info&lt;&lt;&quot; deleted from first&quot;&lt;&lt;endl;
  free(s);
 }
}
void single_llist::delete_last()
 {
   int i, counter = 0;
   struct node *s, *ptr;
   if (start == NULL){}
  else
   { 
      s = start;
    while (s != NULL)
    {
        s = s-&gt;next;
        counter++;
       }
       s=start;
       if(counter==1)
       {
       	start=s->next;
       	cout<<s->info<<"deleted from last"<<endl;
       	free(s);
	   }
	  else
       {
         for (i = 1;i &lt; counter;i++)
         {
            ptr = s; 
            s = s-&gt;next;
          }
          ptr-&gt;next = s-&gt;next;
          cout&lt;&lt;s-&gt;info&lt;&lt;&quot; deleted from last&quot;&lt;&lt;endl;
          free(s);
        }
     }
}
void single_llist::delete_pos()
{
  int pos, i, counter = 0, loc = 1;
   struct node *s, *ptr;
   s = start;
   while (s != NULL)
   {
     s = s-&gt;next;
     counter++;
    }
    if (counter == 0){}
    else
   {
      if (counter == 1)
        {
          cout<<"Enter the postion[SAY"<<loc<<"]:"; 
          cin>>pos;
          s = start;
         if(pos == 1)
         {
           start = s->next;
           cout<<s->info<<"deleted from first"<<endl;
           free(s);
          }
          else
          cout<<"position out of rangr.....!!!"<<endl;
	    }
	    else
	    {
	    	cout<<"enter the position from"<<loc<<"to"<<counter<<":";
	    	cin>>pos;
	    	s=start;
	    	if (pos == 1)
            {
               start =s->next;
               cout<<s->info<<"delete from first"<<endl;
               free(s);
            }
            else if(pos>1&&pos<=counter)
            {
            	for(i=1;i<pos;i+=)
            	{
            		ptr=s;
            		s=s->next;
				}
				ptr->next=s->next;
				if(pos==counter)
				{
					cout<<s->info<<"delete from last"<<endl;
					free(s);
				}
				else
				{
				 cout<<s->info<<"delete from position"<<pos<<endl;
                 free(s);
				 }

                 else
                    cout<<"postion out of range......!!!!!"<<endl;
				}
            }
        }	
	}
void single_llist::update_begin()
   {
     int value, pos=1, i,counter = 0;
     struct node *s, *ptr;
      s = start;
     while (s != NULL)
       {
         s = s-&gt;next;
         counter++;
        }
         if (counter == 0){}
          else if (pos == 1)
            {
              cout<<"enter the new node:";
              cin>>value;
              start->info = value;
              cout<<"node updated at fist postion:"<<pos<<"="<<start->info<<endl;
            }
    }
 void single_llist::update_last()
 {
 	 int value, pos, i,counter = 0;
     struct node *s, *ptr;
     s = start;
     while (s != NULL)
      {
         s =s->next;
         counter++;
        }
         s=start;
          if (counter == 0){}
          else
            {
             cout<<"enter the new node:"
             cin>>value;
              for(i = 1; i &lt; counter ; i++)
                {
                	s=s->next;
	            }
				s->info=value;
				cout<<"node updated at last position:"<<counter<<"="<<s->info<<endl;
				
		    }
    }
void single_llist::update_pos()
{
    int value, pos, i,counter = 0, loc = 1;
    struct node *s, *ptr;
    s = start;
      while (s != NULL)
       {
	      s=s->next;
		  counter++;	
		}
		if (counter == 0){}
          else if (pos == 1)
            {
             cout<<"Enter the new node :";
             cin>>value;
             start->info = value;
             cout<<"Node updated at first position :"<<pos<<"="<<start->info<<endl;
            }
}				
void single_llist::update_last()	
{
	int values,pos,i,counter=0;
	struct node*s,*ptr;
	s=start;
	if (counter == 0){}
       else
        {
         cout&lt;&lt;&quot;Enter the new node : &quot;;
         cin&gt;&gt;value;
for (i = 1; i &lt; counter ; i++)
{
s = s-&gt;next;
}
s-&gt;info = value;
cout&lt;&lt;&quot;Node updated at last position : &quot;&lt;&lt;counter&lt;&lt;&quot; = &quot;&lt;&lt;s-&gt;info&lt;&lt;endl;
}
}
			}			
				
				
				
				
				
				
				   
            	
            	
            	
            	
            	
            	
            	
            	
            	
            	
            	
            	
            	
            	
			
		
