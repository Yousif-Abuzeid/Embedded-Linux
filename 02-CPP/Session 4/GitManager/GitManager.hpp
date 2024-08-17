#ifndef GIT_MANAGER
#define GIT_MANAGER
#include <string>
class GitManager {
    private:
    static const std::string Token;
    static const std::string UserName;
    std::string m_files;
    void printTemplate();

    public:
    GitManager();
    
    bool add();
    bool commit();
    bool push();
    bool pull();
    bool clone();
    void status();
    bool log();
    bool CheckExistence();
    std::string getFiles();
    static std::string RepoName;


};
#endif // !GIT_MANAGER
