#include "GitManager.hpp"
#include <iostream>
#include <string>



const std::string GitManager::Token="";
const std::string GitManager::UserName="Yousif-Abuzeid";
std::string GitManager::RepoName="Embedded-Linux";

GitManager::GitManager()
{
    
}

void GitManager::printTemplate()
{
    std::string form = R"(echo "#cpp - manage - git " >> README.md
git init
git add README.md
git commit -m "first commit
git branch -M main
git remote add origin <remote link > like -> https://github.com/Yousif-Abuzeid/Embedded-Linux.git
")";
    std::cout << form << std::endl;
}

bool GitManager::add()
{
    std::string answer="Y";
    std::cout<<"Do you want to add all files? (Y/N): ";
    std::getline(std::cin,answer);
    if(answer=="Y" || answer=="y")
    {
        std::string command="git add .";
        int result=system(command.c_str());
        if(result==0)
        {
            std::cout<<"Added Successfully"<<std::endl;
            return true;
        }
        else
        {
            std::cout<<"Failed to Add"<<std::endl;
            return false;
        }
    }
    else if(answer=="N" || answer=="n")
    {
    std::cout<<"Enter Files to Add: ";
    std::getline(std::cin,m_files);
    if(m_files.empty())
    {
        std::cout<<"No Files to Add"<<std::endl;
        return false;
    }else if(m_files.find('/') || m_files.find(';') || m_files.find('&') || m_files.find('|')){
        std::cout<<"Invalid File Name"<<std::endl;
        std::cout<<"Usage: FileName1 FileName2 FileName3 ..."<<std::endl;
        return false;
    }

    std::string command="git add "+m_files;
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Added Successfully"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Failed to Add"<<std::endl;
        return false;
    }

}
return false;
}

bool GitManager::commit()
{
    std::string CommitMessage;
    std::cout<<"Enter Commit Message: ";
    std::getline(std::cin,CommitMessage);
    std::string command="git commit -m \""+CommitMessage+"\"";
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Committed Successfully"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Failed to Commit"<<std::endl;
        return false;
    }
}

bool GitManager::push()
{
    std::string answer;
    bool ret = false;
    std::string reponame;
    std::cout << "please write repo name " << std::endl;
    std::getline(std::cin, reponame);
    if (reponame.size() == 0)
    {
        reponame = RepoName;
    }
    std::string github_username;
    std::cout << "please write github username " << std::endl;
    std::getline(std::cin, github_username);
    if (reponame.size() == 0)
    {
        github_username = UserName;
    }
    std::string cmd(" git push https://" + Token + "@github.com/" + github_username + "/" + reponame + ".git");

    // git push https://<GITHUB_ACCESS_TOKEN>@github.com/<GITHUB_USERNAME>/<REPOSITORY_NAME>.git

    std::cout << "would you prefer to use defult (token-name) Y/N ?" << std::endl;
    std::getline(std::cin, answer);

    switch (answer[0])
    {
    case 'Y':
    case 'y':
        std::cout << "Pushing now" << std::endl;
        ret = std::system(cmd.c_str());
        break;

    default:
        std::string access_token;
        std::string name;
        std::cout << "please insert your name" << std::endl;
        std::getline(std::cin, name);
        std::cout << "please insert your access token" << std::endl;
        std::getline(std::cin, access_token);
        std::string cmd(" git push https://" + access_token + "@github.com/" + name + "/" + reponame + ".git");
        ret = std::system(cmd.c_str());
        break;
    }
    return ret;

}

bool GitManager::pull()
{
    std::string command="git pull";
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Pulled Successfully"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Failed to Pull"<<std::endl;
        return false;
    }
}

bool GitManager::clone()
{
    std::string CloneUserName;
    std::string CloneRepoName;
    std::cout<<"Enter UserName: ";
    std::getline(std::cin,CloneUserName);
    std::cout<<"Enter RepoName: ";
    std::getline(std::cin,CloneRepoName);
    
    std::string command="git clone https://"+CloneUserName+":"+Token+"@github.com/"+CloneUserName+"/"+CloneRepoName;
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Cloned Successfully"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Failed to Clone"<<std::endl;
        return false;
    }
}

void GitManager::status()
{
    std::string command="git status";
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Status Checked Successfully"<<std::endl;
    }
    else
    {
        std::cout<<"Failed to Check Status"<<std::endl;
    }
}
bool GitManager::log(){
    std::string command="git log";
    int result=system(command.c_str());
    if(result==0)
    {
        std::cout<<"Log Checked Successfully"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Failed to Check Log"<<std::endl;
        return false;
    }
}