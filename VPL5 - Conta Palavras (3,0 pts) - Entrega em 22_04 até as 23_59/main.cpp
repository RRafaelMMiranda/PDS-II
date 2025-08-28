#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main(void) {
  std::string recebaarquivo;
  std::cin >> recebaarquivo;

  std::ifstream in(recebaarquivo);
  char c;
  std::string palavralidaverdadeira;
  std::map<std::string, int> mapa;

  while (in.get(c)) {
    if (isalnum(c)) {
      c = tolower(c);
      palavralidaverdadeira.push_back(c);
    }
    else if (!palavralidaverdadeira.empty()) {
        if (mapa.find(palavralidaverdadeira) != mapa.end()) {
          mapa[palavralidaverdadeira]++;
        } else
      mapa.insert(std::pair<std::string, int> {palavralidaverdadeira, 1});
      palavralidaverdadeira.clear();
    }
  }

  if (!palavralidaverdadeira.empty()) {
    mapa[palavralidaverdadeira]++;
  }

  for (const auto& par : mapa) {
    std::cout << par.first << " " << par.second << std::endl;
  }
}