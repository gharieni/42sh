# 42sh

## Current tasks

- Midrissi : core of the project (parser, lexer, executor, ...)
- Aben-azz : termcaps/prompt
- Ghamelek : test_builtin/has_table
- tlechien : cd_builtin/jobs control/signal monitoring/alias

## TODO

- Complete management of the history:
	◦ Expansions:
	∗ !!
	∗ !word
	∗ !number
	∗ !-number
	◦ Saving to a file so that it can be used over several sessions
	◦ Built-in fc (all POSIX options)
	◦ Incremental search in the history with CTRL-R
- Contextual dynamic completion of commands, built-ins, files, internal and environment variables. What is meant by contextual? re-we use the “ls /” command
and your cursor is on the /, then a contextual completion will only propose the
content of the root folder and not the commands or built-ins. Same for this case:
“echo ${S”, the completion should only propose variable names that start with S,
whether internal or environmental.
- builtin test
- POSIX norme on builtins
- Signal monitoring.
- Error management.


## DEBUG

error commands that require prompt reading

## DONE

- Prompt
- Lexer
- Parser
- exec + fork + jobs
- builtin_jobs, fg, bg
- builtin_alias, unalias
