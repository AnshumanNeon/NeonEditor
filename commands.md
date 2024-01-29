# Commands

The editor includes a command mode, inspired by emacs and vim. It includes various commands, none of which are longer than 3 characters.
Instead of depending on modifier keys for commands, the editor makes use of normal keys.
* Firstly the user enters command mode and everything is treated as a command.
* Commands are case sensitive and hence increase flexibility while reducing number of keystrokes.
* Commands can put together in any order (except a few).
* When the command is executed the editor places executes the respective actions in order.
* It puts the respective actions in a block and iterates over the actions until complete.
* This approach gives the editor the flexibility of Emacs and Vim as if it was a language.
