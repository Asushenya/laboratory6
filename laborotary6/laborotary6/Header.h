#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);

class String
{
private : 
    char *array;
public :
    String()
    {
        array = new char[256];
        strcpy(array, "empty");
    }
    String(char*p)
    {
        array = new char[256];
        strcpy(array, p);
    }

    String(String& c)
    {
        array = new char[256];
        strcpy(this->array, c.array);
    }

    String(String *c)
    {
        strcpy(this->array, c->array);
    }


    ~String()
   {
       delete[] array;
    }


   void showString()
    {
        int i = 0;
        while (*(array + i))
        {
            cout << *(array + i);
            i++;
        }
        cout << endl;
       
   
    }



    friend void operator << (ostream& output,  String& s)
    {
        output << s.array<<endl;
    }

      void operator - (int i)
    {
        for (int k = i;k < strlen(array);k++)
        {
            array[k] = array[k + 1];
        }
        *(array + strlen(array) ) = '\0';
    }

      bool operator > (char *p)
      {
          int counter = 0;
             

             for (int k = 0;k < strlen(array);k++)
                      {

                          if (array[k] == p[counter])
                          {
                              counter++;
                                  if (counter == strlen(p))
                                      {
                                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
                                          cout << " � " << typeid(String).name() << " ������ ������ '"<<p<<"' \n";
                                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                                          return true;
                                      }
                          }
                          else counter = 0;
                      }

        
             SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "�� ������\n";
                 SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
           
      }


      bool operator > (String p)
      {
          int counter = 0;

          if (p.Length() <= this->Length())
          {

              for (int i(0);i < this->Length();i++)
              {
                  if (this->array[i] == p[counter])
                  {
                      counter++;
                      if (counter == p.Length())
                      {
                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
                          cout <<"� ������ "<<typeid(*this).name()<< " ������ "<<typeid(&p).name()<<endl;
                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                          return true;
                      }
                  }
                  else counter = 0;
              }
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "�� ������\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
          }
          else
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "�� ������\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
          }
      }


      bool operator != (char *s)
      {
          if (this->Length() != strlen(s))
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "������ �� ����� (������)\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return true;
          }

          else
          {
              for (int i = 0;i < this->Length();i++)
              {
                  if (array[i] != s[i])
                  {
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
                      cout << "������ �� ����� (������������ ���������)\n";
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                      return true;
                  }
              }
          }

          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
          cout << "������ ���������\n";
          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
          return false;
      }



      bool operator != (String s)
      {
          if (this->Length() != s.Length())
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "������ �� ����� (������)\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return true;
          }

          else
          {
              for (int i = 0;i < this->Length();i++)
              {
                  if (array[i] != s[i])
                  {
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
                      cout << "������ �� ����� (������������ ���������)\n";
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                      return true;
                  }
              }
          }

          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
          cout << "������ ���������\n";
          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
          return false;
      }

      void operator+( char& p )
      {
          int i;
          cout << "���� ���������?" << endl;
          cin >> i;
          if (i > strlen(array)) { cout << "�� ������� ��������� �������\n"; return; }

          for (int j = strlen(this->array);j>=i;j--)
          {
              this->array[j + 1] = this->array[j];
          }
          this->array[i] = p;
      }

      int Length()
      {
          return strlen(array);
      }
   
      void operator+(char s)
      {
       strcat(array , &s);
      }

      char operator[](int i)
      {
          if (i > this->Length())
              return false;
          else
          return array[i];
      }

     
};