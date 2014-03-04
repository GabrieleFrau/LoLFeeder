//
//  curl_message.h
//  curlcpp
//
//  Created by Giuseppe Persico on 11/02/14.
//  Copyright (c) 2014 Giuseppe Persico. All rights reserved.
//

#ifndef __curlcpp__curl_message__
#define __curlcpp__curl_message__

#include "curl_multi.h"

using curl::curl_multi;

namespace curl {
    class curl_multi::curl_message {
    public:
        curl_message(CURLMSG message, curl_easy curl, void *whatever, CURLcode result) : message(message), curl(curl), whatever(whatever), result(result) {};
        const CURLMSG get_message() const noexcept;
        const CURLcode get_result() const noexcept;
        const curl_easy get_curl() const noexcept;
        const void *get_whatever() const noexcept;
    private:
        CURLMSG message;
        curl_easy curl;
        void *whatever;
        CURLcode result;
    };
}

#endif /* defined(__curlcpp__curl_message__) */