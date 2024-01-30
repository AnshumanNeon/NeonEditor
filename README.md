# Neon Editor

Neon Editor is a modern editor that puts focus on developer experience and increase typing speed of the developer. The editor pays special focus on making itself extremely fast, both to load and to use.

## Features:

* *Non-Modal*: Neon editor is a non-modal editor, i.e. it doesn't rely on modes such as Vim for its functionality. This is to integrate the use of commands while you type them. 
* *Commands*: N-ed (short-hand for Neon-editor) uses commands for most functions. This is similar to editors like Emacs and Vim.
* *Flexible*: N-ed is an extremely flexible editor that allows you to customize it to your liking. In future, it will use a programming language similar to, or, lua for this like NeoVim does.
* *Code Management*: It offers syntax highlighting, easy navigation and might include code completion in future.
* *Fast*: It is a feature that is kept in mind from the beginning to make both the application and your speed faster.
* *Easy to learn*: N-ed requires commitment, but it tries its best to make the learning curve easy for newcomers.

## But-

### The Problem

But this poses a critical problem that needs to be resolved: "How does the editor differentiate normal text typing from commands?".

The solution for this is a "command palette". Now command palette doesn't refer to the list of commands as you may guess, it refers to a widget, buffer or whatever you may call it, where you type the commands. This is similar to switiching modes to type commands and type text.

But if you're using need to open command palette again and again, then that makes job harder! Hence to tackle this a new approach has been taken.

### The Approach / Solution

The command palette, by default, will *not* be active, whatever you type will be seen as text and will be typed on the screen. To type commands you need to have Caps-lock on, if your caps-lock key is on then everything you type will be interpreted as command. After you press enter, the command palette will be disabled and you need to open it again to type the next commands.
In order to increase efficiency, you can divide commands by semicolons (";"). This way you don't need to enable the command palette again and again.
But what if you need to use the caps-lock key to type long strings of capitalized content?
There are two solutions to this:
* *type-first-capitalize-later*: N-ed includes commands that can select a piece of text and then you can capitalize them all at once.
* *New key*: If you want to use a toggle key for this, N-ed provides the key-combination of Ctrl+e to do so. You can also map a key of your liking for this action.

## Note

Most of the features aren't implemented yet. The project is under development.
