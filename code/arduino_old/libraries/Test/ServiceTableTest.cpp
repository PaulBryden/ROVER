
//#include "../Comms/Comms.cpp"
#include "../Comms/ServiceTable.cpp"
#include "../Comms/Service.cpp"


#include <stdio.h>



int blackbox(){
  ServiceTable table;
  byte id1 = 0;
  byte id2 = 1;
  Service s1 = Service(id1, "Test Service");

  if (table.getService(id1) != NULL) {
    return 0;
  }


  table.addService(&s1);

  Service * s2 = table.getService(id1);

  if (s2 == NULL){
    return 0;
  } else if (!(s1.getName().compare(s2 -> getName()))){
    return 0;
  } else if (!(s1.getId() == s2 -> getId())){
    return 0;
  }
  /*delete s1;
  if (table.getService(id) != NULL){
    return 0;
  }*/
  delete s2;
  return 1;
}
int main(){
  printf ("%d", blackbox());

  return 0;
}
