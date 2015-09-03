// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sleep.c


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()

using std::cout;


main ( )
{

  double x = 1;
  for(int i=0; i<5; i++) {
    sleep(i);
   cout << x +i << '\n';
  }
  cout << "Buummmm ";
  //   std::cout << x <<'\n'; 
}

