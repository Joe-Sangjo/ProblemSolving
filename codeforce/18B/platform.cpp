#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class EbayKorea{
	public:
		string SiteName;
		string Region;

		EbayKorea(string siteName, string region){
			this->SiteName = siteName;
			this->Region = region;
		}
		virtual string Print(){
			return "**Welcome to EbayKorea!\n";
		}
};
/*
 * Complete the Classes below.
 */
class GMarket : public EbayKorea{
public:
    GMarket(string siteName, string region) : EbayKorea(siteName, region){
    }
    string Print(){
  	return "Welcome to GMarket!\n";

    }
};

class Auction : public EbayKorea{
public:
    Auction(string siteName, string region) : EbayKorea(siteName, region){
    }
    string Print(){
  	return "Welcome to Auction!\n";
  }
};

int main(){



	return 0;
}