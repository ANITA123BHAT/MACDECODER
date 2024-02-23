#ifndef MACDECODER_H
#define MACDECODER_H
#include<iostream>
#include <fstream>
#include "mac_decoder.h"
using namespace std;
MAC_HEADER obj2;

/*Function to read the content of file for Downlink*/
// void read_file_for_DL(){
//     ifstream file1("output_DL.txt");
//     if (file1.is_open()) {
//         std::string line;

//         // Read and print content from output_DL.txt line by line
//         std::cout << "Contents of output_DL.txt:" << std::endl;
//         while (std::getline(file1, line)) {
//             std::cout << line << std::endl;
//         }
//         std::cout << std::endl;
//         file1.close(); // Close output_DL.txt
//     }
//     else{
//         std::cout << "Unable to open the file." << std::endl;
//     }
// }
// /* Function to read the content of file for Uplink */
// void read_file_for_UL(){
//     ifstream file2("output_UL.txt");
//     if (file2.is_open()) {
//         std::string line;

//         // Read and print content from output_UL.txt line by line
//         std::cout << "Contents of output_DL.txt:" << std::endl;
//         while (std::getline(file2, line)) {
//             std::cout << line << std::endl;
//         }
//         std::cout << std::endl;
//         file2.close(); // Close output_UL2.txt
//     }
//     else{
//         std::cout << "Unable to open the file." << std::endl;
//     }
// }
// bool validation(string hexaval){
//     if((hexaval.length())!=2){
//         return false;
//     }
//      for(size_t i = 0; i < hexaval.length(); i++)
//     {
//         // }
//         if (!((hexaval[i] >= '0' && hexaval[i] <= '9') || (hexaval[i] >= 'A' && hexaval[i] <= 'F') || (hexaval[i] >= 'a' && hexaval[i] <= 'f'))) {
//             return false;
//         }
//     }
//     return true;
// }

/* Function to print and store the value of LCID in file for Downlink*/
void print_downlink_LCID_val(int lcid_val){
    cout<<" LCID Val for the given user input in downlink "<<endl;
    //ofstream outputFile("output1_DL.txt",ios::out|ios::app);// Open the file for writing
    fstream file;
    file.open("output_DL.txt", ios::in | ios::out | ios::app);
    if (file.is_open()) {
    file<<"LCID Val for the given user input in downlink"<<endl;
    switch(lcid_val){
        case 0:
            cout<<" CCCH"<<endl;
            file << "CCCH" << std::endl;
            break;
        case 1 ... 10 :
            cout<<" Identity of the logical channel"<<endl;
            file << "Identity of the logical channel" << std::endl;
            break;
        case 11 ... 25:
            cout<<" Reserved"<<endl;
            file << "Reserved" << std::endl;
            break;
        case 26:
            cout<<" Long DRX Command"<<endl;
            file <<"Long DRX Command" << std::endl;
            break;
        case 27:
            cout<<" Activation/Deactivation"<<endl;
            file << "Activation/Deactivation" << std::endl;
            break;
        case 28:
            cout<<" UE Contention Resolution Identity "<<endl;
            file << "UE Contention Resolution Identity" << std::endl;
            break;
        case 29:
            cout<<" Timing Advance Command"<<endl;
            file<< "Timing Advance Command" << std::endl;
            break;
        case 30:
            cout<<" DRX Command "<<endl;
            file << " DRX Command" << std::endl;
            break;
        case 31:
            cout<<" Padding"<<endl;
            file<<"Padding" << std::endl;
            break;
        default :
            cout<<" Invalid LCID"<<endl;
            break;
    }
   file.close(); 
    }
     else {
        cout << " Unable to open the file. " <<endl;
    }
}
/* Function to print and store the value of LCID in file for Uplink*/
void print_uplink_LCID_val(int lcid_val){
    cout<<" LCID Val for the given user input in uplink "<<endl;
    //ofstream outputFile1("output2_UL.txt",ios::out|ios::app);// Open the file for writing
    fstream file1;
    file1.open("output_UL.txt", ios::in | ios::out | ios::app);
    if (file1.is_open()) {
    file1<<"LCID Val for the given user input in uplink"<<endl;
    switch(lcid_val){
        case 0:
            cout<<" CCCH"<<endl;
            file1<< "CCCH" <<endl;
            break;
        case 1 ... 10 :
            cout<<" Identity of the logical channel"<<endl;
            file1 << "Identity of the logical channel" <<endl;
            break;
        case 11:
            cout<<" CCCH"<<endl;
            file1 << "CCCH" <<endl;
            break;
        case 12 ... 21:
            cout<<" Reserved"<<endl;
            file1 << "Reserved" <<endl;
            break;
        case 22:
            cout<<" Truncated Sidelink BSR"<<endl;
            file1<< "Truncated Sidelink BSR" <<endl;
            break;
        case 23:
            cout<<" Sidelink BSR  "<<endl;
            file1<< "Sidelink BSR" <<endl;
            break;
        case 24:
            cout<<"Dual Connectivity Power Headroom Report"<<endl;
            file1 << "Dual Connectivity Power Headroom Report" <<endl;
            break;
        case 25:
            cout<<" Extended Power Headroom Report "<<endl;
            file1 << "Extended Power Headroom Report" <<endl;
            break;
        case 26:
            cout<<" Power Headroom Report "<<endl;
            file1 << "Power Headroom Report" <<endl;
            break;
        case 27:
            cout<<" C-RNTI "<<endl;
            file1 << "C-RNTI" <<endl;
            break;
        case 28:
            cout<<" Truncated BSR "<<endl;
            file1<< "Truncated BSR" <<endl;
            break;
        case 29:
            cout<<" Short BSR "<<endl;
            file1<< "Short BSR" <<endl;
            break;
        case 30:
            cout<<" Long BSR "<<endl;
            file1 << "Long BSR" <<endl;
            break;
        case 31:
            cout<<" Padding "<<endl;
            file1 << "Padding" <<endl;
            break;
        default :
            cout<<"Invalid LCID"<<endl;
            break;
    }
    file1.close();
    }
    else {
        cout << " Unable to open the file. " <<endl;
    }
}

/*Function to find value of subheader Downlink*/
void find_subheader_val_DL(uint8_t data, MAC_HEADER& sub_head){
    fstream file2;
    file2.open("output_DL.txt", ios::in | ios::out | ios::app);
    if (file2.is_open()) {
    sub_head.R1=(data >> 7) & 1;
    cout<<"\n";
    cout<<" Value of R1: "<<static_cast<int>(sub_head.R1)<<endl;
    file2<<"Value of R1="<<static_cast<int>(sub_head.R1)<<endl;
    sub_head.R2=(data >> 6) & 1;
    cout<<" Value of R2: "<<static_cast<int>(sub_head.R2)<<endl;
    file2<<"Value of R2="<<static_cast<int>(sub_head.R2)<<endl;
    sub_head.E =(data >> 5) & 1;
    cout<<" Value of E: "<<static_cast<int>(sub_head.E)<<endl;
    file2<<"Value of E="<<static_cast<int>(sub_head.E)<<endl;
    file2.close();
    }
    else{
        cout << " Unable to open the file. " <<endl;
    }

    sub_head.LCID = data & 0x1F;
    int lcid_data = static_cast<int> (sub_head.LCID);
    print_downlink_LCID_val(lcid_data);
}

/* Function to find value of subheader Uplink */
void find_subheader_val_UL(uint8_t data, MAC_HEADER& sub_head){
    fstream file3;
    file3.open("output_UL.txt", ios::in | ios::out | ios::app);
    if (file3.is_open()) {
    sub_head.R1=(data >> 7) & 1;
    cout<<"\n";
    cout<<" Value of R1: "<<static_cast<int>(sub_head.R1)<<endl;
    file3<<"Value of R1="<<static_cast<int>(sub_head.R1)<<endl;
    sub_head.R2=(data >> 6) & 1;
    cout<<" Value of R2: "<<static_cast<int>(sub_head.R2)<<endl;
    file3<<"Value of R2="<<static_cast<int>(sub_head.R2)<<endl;
    sub_head.E =(data >> 5) & 1;
    cout<<" Value of E: "<<static_cast<int>(sub_head.E)<<endl;
    file3<<"Value of E="<<static_cast<int>(sub_head.E)<<endl;
    file3.close();
    }
    else{
        cout << " Unable to open the file. " <<endl;
    }
    sub_head.LCID = data & 0x1F;
    int lcid_data = static_cast<int> (sub_head.LCID);
    print_uplink_LCID_val(lcid_data);
}

/* function to start with find value of LCID for downlink*/
void downlink(string hexa_val){
    cout<<" user input value "<< hexa_val<<endl;
    uint8_t dec_hex = stoi(hexa_val, 0, 16);
    find_subheader_val_DL(dec_hex,obj2);
}

/* function to start with find value of LCID for uplink*/
void uplink(string hexa_val){
    cout<<" user input value "<< hexa_val<<endl;
    uint8_t dec_hex = stoi(hexa_val, 0, 16);
    find_subheader_val_UL(dec_hex,obj2);
}

#endif