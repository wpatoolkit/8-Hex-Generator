#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
char add1(char c) { c = toupper(c); return c=='0'?'1':c=='1'?'2':c=='2'?'3':c=='3'?'4':c=='4'?'5':c=='5'?'6':c=='6'?'7':c=='7'?'8':c=='8'?'9':c=='9'?'A':c=='A'?'B':c=='B'?'C':c=='C'?'D':c=='D'?'E':c=='E'?'F':c=='F'?'0':c; }
char minus1(char c) { c = toupper(c); return c=='0'?'F':c=='1'?'0':c=='2'?'1':c=='3'?'2':c=='4'?'3':c=='5'?'4':c=='6'?'5':c=='7'?'6':c=='8'?'7':c=='9'?'8':c=='A'?'9':c=='B'?'A':c=='C'?'B':c=='D'?'C':c=='E'?'D':c=='F'?'E':c; }
char combo1_flipchar(char c) { c = toupper(c); return c=='1'?'2':c=='2'?'4':c=='3'?'6':c=='4'?'1':c=='5'?'3':c=='6'?'5':c=='9'?'A':c=='A'?'C':c=='B'?'E':c=='C'?'9':c=='D'?'B':c=='E'?'D':c; }
char combo2_flipchar(char c) { c = tolower(c); return c=='0'?'9':c=='1'?'4':c=='2'?'4':c=='3'?'6':c=='4'?'2':c=='5'?'6':c=='6'?'3':c=='9'?'a':c=='a'?'c':c=='b'?'e':c=='c'?'9':c=='d'?'b':c=='e'?'d':c; }
void append_results(char c1,char c2,char c3,char c4,char c5,char c6,char c7,char c8) {
 // 62385174
 std::cout << combo1_flipchar(c6) << combo1_flipchar(c2) << combo1_flipchar(c3) << combo1_flipchar(c8) << combo1_flipchar(c5) << combo1_flipchar(c1) << combo1_flipchar(c7) << combo1_flipchar(c4) << std::endl;
 std::cout << combo2_flipchar(c6) << combo2_flipchar(c2) << combo2_flipchar(c3) << combo2_flipchar(c8) << combo2_flipchar(c5) << combo2_flipchar(c1) << combo2_flipchar(c7) << combo2_flipchar(c4) << std::endl;
 // 12385174
 std::cout << combo1_flipchar(c1) << combo1_flipchar(c2) << combo1_flipchar(c3) << combo1_flipchar(c8) << combo1_flipchar(c5) << combo1_flipchar(c1) << combo1_flipchar(c7) << combo1_flipchar(c4) << std::endl;
 std::cout << combo2_flipchar(c1) << combo2_flipchar(c2) << combo2_flipchar(c3) << combo2_flipchar(c8) << combo2_flipchar(c5) << combo2_flipchar(c1) << combo2_flipchar(c7) << combo2_flipchar(c4) << std::endl;
 // 12385674
 std::cout << combo1_flipchar(c1) << combo1_flipchar(c2) << combo1_flipchar(c3) << combo1_flipchar(c8) << combo1_flipchar(c5) << combo1_flipchar(c6) << combo1_flipchar(c7) << combo1_flipchar(c4) << std::endl;
 std::cout << combo2_flipchar(c1) << combo2_flipchar(c2) << combo2_flipchar(c3) << combo2_flipchar(c8) << combo2_flipchar(c5) << combo2_flipchar(c6) << combo2_flipchar(c7) << combo2_flipchar(c4) << std::endl;
 // 62385674
 std::cout << combo1_flipchar(c6) << combo1_flipchar(c2) << combo1_flipchar(c3) << combo1_flipchar(c8) << combo1_flipchar(c5) << combo1_flipchar(c6) << combo1_flipchar(c7) << combo1_flipchar(c4) << std::endl;
 std::cout << combo2_flipchar(c6) << combo2_flipchar(c2) << combo2_flipchar(c3) << combo2_flipchar(c8) << combo2_flipchar(c5) << combo2_flipchar(c6) << combo2_flipchar(c7) << combo2_flipchar(c4) << std::endl;
}
void process_mac(std::string router_mac, bool add_variations=false) {
 // uppercase
 std::transform(router_mac.begin(), router_mac.end(),router_mac.begin(), ::toupper);
 // strip colons
 router_mac = router_mac.substr(0,2) + router_mac.substr(3,2) + router_mac.substr(6,2) + router_mac.substr(9,2) + router_mac.substr(12,2) + router_mac.substr(15,2);
 // strip first 2 octets
 router_mac = router_mac.substr(4);
 // populate byte array
 char *mac_chars, orig_mac_6, orig_mac_7;
 mac_chars = &router_mac[0u];
 orig_mac_6 = mac_chars[6];
 orig_mac_7 = mac_chars[7];
 // uppercase byte array
 //for (int i=0;i<sizeof(mac_chars);++i) { mac_chars[i] = toupper(mac_chars[i]); }
 // mac
 append_results(mac_chars[0],mac_chars[1],mac_chars[2],mac_chars[3],mac_chars[4],mac_chars[5],mac_chars[6],mac_chars[7]);
 if (add_variations) {
  // mac +1
  mac_chars[6] = (orig_mac_7 == 'F') ? add1(orig_mac_6) : orig_mac_6;
  mac_chars[7] = add1(orig_mac_7);
  append_results(mac_chars[0],mac_chars[1],mac_chars[2],mac_chars[3],mac_chars[4],mac_chars[5],mac_chars[6],mac_chars[7]);
  // mac +2
  mac_chars[6] = (orig_mac_7 == 'E') ? add1(orig_mac_6) : orig_mac_6;
  mac_chars[7] = add1( add1(orig_mac_7) );
  append_results(mac_chars[0],mac_chars[1],mac_chars[2],mac_chars[3],mac_chars[4],mac_chars[5],mac_chars[6],mac_chars[7]);
  // mac -1
  mac_chars[6] = (orig_mac_7 == '0') ? minus1(orig_mac_6) : orig_mac_6;
  mac_chars[7] = minus1(orig_mac_7);
  append_results(mac_chars[0],mac_chars[1],mac_chars[2],mac_chars[3],mac_chars[4],mac_chars[5],mac_chars[6],mac_chars[7]);
  // mac -2
  mac_chars[6] = (orig_mac_7 == '1') ? minus1(orig_mac_6) : orig_mac_6;
  mac_chars[7] = minus1( minus1(orig_mac_7) );
  append_results(mac_chars[0],mac_chars[1],mac_chars[2],mac_chars[3],mac_chars[4],mac_chars[5],mac_chars[6],mac_chars[7]);
 }
}
int main(int argc, char *argv[]) {
 std::string router_mac;
 if (argc > 1) {
  router_mac = argv[1];
  if (router_mac.length() == 12) { router_mac = router_mac.substr(0,2) + ":" +  router_mac.substr(2,2) + ":" + router_mac.substr(4,2) + ":" + router_mac.substr(6,2) + ":" + router_mac.substr(8,2) + ":" + router_mac.substr(10,2); }
  if (router_mac.length() == 8) { router_mac = router_mac.substr(0,2) + ":" +  router_mac.substr(2,2) + ":" + router_mac.substr(4,2) + ":" + router_mac.substr(6,2); }
  if (router_mac.length() == 11) { router_mac = "XX:XX:" + router_mac; }
  if (router_mac.length() != 17) { std::cout << "Router MAC is not the correct length" << std::endl; return 1; }
  process_mac(router_mac,true);
 }
 else {
  // generate all possible 50,331,648 combinations
  std::string possible_chars[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
  for (int c1=0;c1<16;++c1) { for (int c2=0;c2<16;++c2) { for (int c3=0;c3<16;++c3) { for (int c4=0;c4<16;++c4) { for (int c5=0;c5<16;++c5) { for (int c6=0;c6<16;++c6) {
   process_mac("94:44:52:" + possible_chars[c1] + possible_chars[c2] + ":" + possible_chars[c3] + possible_chars[c4] + ":" + possible_chars[c5] + possible_chars[c6]);
   process_mac("08:86:3B:" + possible_chars[c1] + possible_chars[c2] + ":" + possible_chars[c3] + possible_chars[c4] + ":" + possible_chars[c5] + possible_chars[c6]);
   process_mac("EC:1A:59:" + possible_chars[c1] + possible_chars[c2] + ":" + possible_chars[c3] + possible_chars[c4] + ":" + possible_chars[c5] + possible_chars[c6]);
  } } } } } }
 }
 return 0;
}