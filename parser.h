#include <string>

class parser
{
public:
   static std::string parse(std::string data)
    {
        int k;
        std::string result = "";
        for (int i = 0; i < data.length(); i++)
        {
            if(data[i] > 96 && data[i] < 123)
            {
                result += data[i];

            }
            else
            {
                int count = 0;
                k = 0;
                while(data[i] != '[')
                {
                    count++;
                    k*=10;
                    k+= data[i] - '0';
                    i++;
                }
                int open = 0, close = 0;
                for (int j = i; j < data.length(); j++)
                {
                    if(data[j] == '[')
                        open++;
                    else if(data[j] == ']')
                        close++;
                    if(open == close)
                    {
                        auto srt = data.substr(i,j-i);
                        auto tmp = parse(srt);
                        i = j;
                        for (int q = 0; q < k; q++)
                            result += tmp;
                        break;
                    }

                }

            }

        }
        return result;
    }
};
