#include <iostream>
#include <jsoncpp/json/json.h>
#include "curlcpp/include/curl_easy.h"
#include "curlcpp/include/curl_error.h"

using curl::curl_easy;
using namespace std;
size_t callback( char *ptr, size_t size, size_t nmemb, void *userdata);
int main(int argc, char** argv)
{
  if(argc != 2)
  {
    cout<<"USAGE: "<<argv[0]<<" URL"<<endl;
    return -1;
  }
  Json::Value root; 
  Json::Reader reader;
  curl_easy easy;
  int ret;
  std::string URL = argv[1];
  easy.add_option(curl_pair<CURLoption,string>(CURLOPT_URL,URL) );
  easy.add_option(curl_pair<CURLoption,long>(CURLOPT_FOLLOWLOCATION,1L) );
  easy.add_option(curl_pair<CURLoption,size_t(*)(char *ptr, size_t size, size_t nmemb, void *userdata)>(CURLOPT_WRITEFUNCTION,callback) );
  ret = easy.perform();
  /*bool parsingSuccessful = reader.parse( config_doc, root );
  if ( !parsingSuccessful )
  {
      // report to the user the failure and their locations in the document.
      std::cout << "Failed to parse configuration\n"
		<< reader.getFormattedErrorMessages();
      return -1;
  }*/
  
}
size_t callback( char *ptr, size_t size, size_t nmemb, void *userdata)
{
  cout<<"dsafasf"<<endl;
}