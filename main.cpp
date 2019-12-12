#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

std::ifstream infile("/home/hazhir/Desktop/saeed.txt");
double max[20] = {-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10};
std::vector<std::vector<double>> show(20);
/*double open[10000]; double high[10000]; double low[10000]; double close[10000];
int volume[10000]; double s10[10000]; double s20[10000]; double s30[10000];
double s40[10000];  double s50[10000]; double s60[10000]; double s70[10000];
bool osma[10000]; bool macdm[10000]; bool ma20[10000]; bool rsi[10000];
bool cci[10000]; bool pin_bar[10000]; bool osma_h4[10000]; bool macdm_h4[10000];
bool rsi_h4[10000]; bool cci_h4[10000]; bool pin_bar_h4[10000]; bool osma_d1[10000]; bool macdm_d1[10000];
bool ma20_d1[10000]; bool rsi_d1[10000]; bool cci_d1[10000]; bool pin_bar_d1[10000];*/
std::vector<std::vector<double>> var(10000);

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string line;
    int c; int cc;
    int b; int bb;
    int jj;
    std::getline(infile, line,'\n');
    char * pch;
    int t=0;
    for(int i=0;i<20;i++)
        show[i] = std::vector<double >(6);
    while (std::getline(infile, line,'\n'))
    {
        std::istringstream buffer(line);
        std::vector<std::string> buff(32);
        for(int i=0;i<32;i++)
        {
            buffer >> buff[i];
            if (i>2)
                var[t].push_back(std::stod(buff[i]));
        }
        t++;
    }
    for(float i=1.1;i<=2.1;i+=0.5)
        for(int j=5;j<=11;j++)
            for(int k=12;k<=28;k++)
            {
                c=0; b=0;
                for(int l=0;l<=9831;l++) {
                    if (var[l][k] == 1)
                        c++;
                    if (var[l][j] >= i)
                        b++;
                }
                for(int l=0;l<20;l++) {
                    auto temp = (i * 0.02 * (b / c)) - (0.02 * (1 - (b - c)));
                    if (temp > max[l]) {
                        max[l] = temp;
                        show[l][0] = c;
                        show[l][1] = b;
                        show[l][2]= b/c;
                        show[l][3] = j;
                        show[l][4] = i;
                        show[l][5] = max[l];
                        break;
                    }
                }
            for(jj = k+1;jj<=28;jj++)
            {
                cc=0;
                bb=0;
                for(int l=0;l<=9831;l++) {
                    if (var[l][k] == 1 && var[l][jj] ==1)
                        cc++;
                    if (var[l][j] >= i)
                        bb++;
                }
                for(int l=0;l<20;l++) {
                    if (cc==0)
                        break;
                    auto temp = (i * 0.02 * (bb / cc)) - (0.02 * (1 - (bb - cc)));
                    if (temp > max[l]) {
                        max[l] = temp;
                        show[l][0] = cc;
                        show[l][1] =  bb;
                        show[l][2] = bb/cc;
                        show[l][3] = j;
                        show[l][4] = i;
                        show[l][5] = max[l];
                        break;
                    }
                }
            }
            }
    int ttt =0;
    return 0;
}
