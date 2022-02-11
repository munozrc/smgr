#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc == 1 || argc != 3)
  {
    cout << "Type help command" << endl;
    return 1;
  }

  string action = argv[1];
  string content = argv[2];

  string services[3] = {"OracleServiceXE", "OracleXETNSListener", "TeamViewer"};
  int sizeServices = sizeof(services) / sizeof(services[0]);

  if (action == "start")
  {
    for (int i = 0; i < sizeServices; i++)
    {
      string command = "net start " + services[i];
      system(command.c_str());
    }
  }
  else if (action == "stop")
  {
    for (int i = 0; i < sizeServices; i++)
    {
      string command = "net stop " + services[i];
      system(command.c_str());
    }
  }
  else if (action == "config")
  {
    for (int i = 0; i < sizeServices; i++)
    {
      string command = "sc config " + services[i] + " start=demand";
      system(command.c_str());
    }
  }

  return 0;
}