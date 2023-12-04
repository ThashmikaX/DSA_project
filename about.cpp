// aboutus.cpp
#include "about.h"
#include <iostream>
#include "menu.h"

using namespace std;

void aboutPage() {
    cout << "-------Welcome to Nexgen Finance, where your financial well-being is our top priority.------\n";
    //cout << "\n--------------------------------------------------------------------------------------------\n\n\n";
    cout << "\033[1m" << "-------------------------Our Vision--------------------------------------------------------\n" << "\033[0m" << endl;
    cout << "At Nexgen Finance, we are committed to providing you with the highest level of banking\n"
            "services while maintaining the utmost integrity and transparency. Our mission is to\n"
            "empower individuals and businesses to achieve their financial goals through\n"
            "innovative and reliable solutions.\n\n"<<endl;
    
    cout << "\033[1m" << "-------------------------Who we are---------------------------------------------------------\n" << "\033[0m" << endl;

    cout << "Established in 2023, Nexgen Finance has been a trusted financial institution dedicated to\n"
            "serving the community. With a team of experienced professionals and cutting-edge\n"
            "etechnology, we strive to deliver banking services that exceed your expectations.\n\n"<<endl;

    
    cout << "\033[1m" << "-------------------------Contact Us---------------------------------------------------------\n" << "\033[0m" << endl;

    cout << "Have questions or need assistance? Our dedicated customer support team is available\n"
            "s24/7 to assist you. Reach out to us at nexgenfinance.com\n"
            "Hotline Main office Galle  +94115928400\n"
            "                    Matara +94115209335\n\n\n"
            "Thank you for choosing NexGen Finance. We look forward to being your trusted financial \n"
            "partner"<<endl;
            //cout << "------------------------------------------------------------------------------------------------------\n\n\n";
             while(true){
            cout << "\nDo you continue?\n";
            cout <<"1.Yes\n";
            cout <<"2.No\n";
            cout <<"Select your option: ";
            int z;
            cin >>z;
            if(z<3 || z>0){
                if(z==1){
                    menu();

                }else{
                    break;
                    
                }
            }
            }
}

       
   

