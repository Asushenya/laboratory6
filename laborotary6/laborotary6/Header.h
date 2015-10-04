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

   int Length()
   {
       return strlen(array);
   }

   /////////////////////////    <<
    friend void operator << (ostream& output,  String& s) // console output
    {
        output << s.array<<endl;
    }

    ///////////////////////   -
      void operator - (int i)
    {
        for (int k = i;k < strlen(array);k++)
        {
            array[k] = array[k + 1];
        }
        *(array + strlen(array) ) = '\0';
    }

      //////////////////////////// >
      bool operator > (char *p) //general array
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
                                          cout << " В " << typeid(String).name() << " входит строка '"<<p<<"' \n";
                                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                                          return true;
                                      }
                          }
                          else counter = 0;
                      }

        
             SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "Не входит\n";
                 SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
           
      }


      bool operator > (String p) //class String
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
                          cout <<"В строку "<<typeid(*this).name()<< " Входит "<<typeid(&p).name()<<endl;
                          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                          return true;
                      }
                  }
                  else counter = 0;
              }
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "Не входит\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
          }
          else
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "Не входит\n";
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
              return false;
          }
      }


      ///////////////////////// !=

      bool operator != (char *s) // general array
      {
          if (this->Length() != strlen(s))
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "Строки не равны (размер)\n";
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
                      cout << "Строки не равны (посимвольное сравнение)\n";
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                      return true;
                  }
              }
          }

          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
          cout << "Строки идентичны\n";
          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
          return false;
      }



      bool operator != (String s) // class String
      {
          if (this->Length() != s.Length())
          {
              SetConsoleTextAttribute(hConsole1, (WORD)((2 << 3) | 12));
              cout << "Строки не равны (размер)\n";
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
                      cout << "Строки не равны (посимвольное сравнение)\n";
                      SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
                      return true;
                  }
              }
          }

          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
          cout << "Строки идентичны\n";
          SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 7));
          return false;
      }

     ////////////////////////// +
      void operator+( char& p ) // one symbol
      {
          int i;
          cout << "куда вставляем?" << endl;
          cin >> i;
          if (i > strlen(array)) { cout << "Не удалось выполнить вставку\n"; return; }

          for (int j = strlen(this->array);j>=i;j--)
          {
              this->array[j + 1] = this->array[j];
          }
          this->array[i] = p;
      }


   
      void operator+(char *string) // general array
      {
          strcat(array, string);
      }

      void operator + (String stringObj) //object of class String
      {
          strcat(array, stringObj.array);
      }

      ////////////////////////// []

      char operator[](int i)
      {
          if (i > this->Length())
              return false;
          else
          return array[i];
      }

     
};