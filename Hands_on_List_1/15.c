/*
============================================================================
Name : 15.c
Author : Ayyan Pasha
Description : Write a program to display the environmental variable of the user (use environ).
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>	// Import `NULL` and `environ`

extern char ** environ;

int main(){
	char **it = environ;
	while(*it){
		printf("%s\n",*it);
		it++;
	}
	return 0;
}
/*
./a.out 
MallocNanoZone=0
USER=ayyanpasha
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/usr/local/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin:/Applications/VMware Fusion.app/Contents/Public:/opt/homebrew/bin:/opt/homebrew/sbin
LOGNAME=ayyanpasha
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.4vfQFTiMaa/Listeners
HOME=/Users/ayyanpasha
SHELL=/bin/zsh
TMPDIR=/var/folders/j3/5ck_ljz90sg9s55htv30t6lr0000gq/T/
__CF_USER_TEXT_ENCODING=0x1F7:0x0:0x0
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
SHLVL=1
PWD=/Users/ayyanpasha/Desktop/CSE513-System-Software/Hands_on_List_1
OLDPWD=/Users/ayyanpasha/Desktop/CSE513-System-Software
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.92.2
LANG=en_US.UTF-8
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/j3/5ck_ljz90sg9s55htv30t6lr0000gq/T/vscode-git-20ae23d54e.sock
VSCODE_INJECTION=1
ZDOTDIR=/Users/ayyanpasha
USER_ZDOTDIR=/Users/ayyanpasha
TERM=xterm-256color
_=/Users/ayyanpasha/Desktop/CSE513-System-Software/Hands_on_List_1/./a.out
*/