#include<iostream>
using namespace std;

/* structure to store sub header value */
struct MAC_HEADER{
    uint8_t header;
    uint8_t R1,R2,E,LCID;
};

/* function declaration */
void find_subheader_val_UL(uint8_t hex_dec,MAC_HEADER& var1);
void find_subheader_val_DL(uint8_t hex_dec,MAC_HEADER& var1);
//bool validation(string);
void downlink(string);
void uplink(string);
void print_downlink_LCID_val(int lcid_data);
void print_uplink_LCID_val(int lcid_data);
// void read_file_for_DL();
// void read_file_for_UL();