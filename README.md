# 42-Rank_03-MiniShell
---
## Mainloop
## Tokenizer
#### Token list:

tk_lprnths &rarr; '('  <br>
tk_rprnths &rarr; ')' <br>
tk_sglquot &rarr; ' <br>
tk_dblquot &rarr; " <br>
tk_mul &rarr; '*' <br>
tk_semi &rarr; ';' <br>
tk_less &rarr; '<' <br>
tk_dblless &rarr; '<<' <br>
tk_grt &rarr; '>' <br>
tk_dblgrt &rarr; '>>' <br>
tk_pipe &rarr; '|' <br>
tk_or &rarr; '||' <br>
tk_ampersand &rarr; '&' <br>
tk_and &rarr; '&&' <br>
tk_doll_exc &rarr; '\$\!' <br>
tk_dollar &rarr;'$' <br>
tk_cmd &rarr; 'simple_command' <br>
tk_arg &rarr; 'arguments' <br>
tk_nl &rarr; '\n' <br>
tk_assign &rarr; '='  <br>

<p>&nbsp;</p>
<p>&nbsp;</p>

## Parser
### Minishell Grammar
|**Syntax**  | **Expansion** |
| :--------------- | :--------------------------- |
**complete_command**| &rarr; list separator<br> &ensp; &#124; list <br> &ensp; ;
**list** | &rarr; list separator_op and_or <br> &ensp; &#124; and_or <br> &ensp;;
**and_or** | &rarr; and_or AND_IF linebreak pipeline <br> &ensp; &#124; and_or OR_IF linebreak pipeline <br> &ensp; &#124; pipeline <br> &ensp; ;
**pipeline** |  &rarr; pipesequence <br> &ensp; &#124; Bang pipe_sequence <br> &ensp; ;
**pipesquence** |  &rarr; command <br> &ensp; &#124; pipe_sequence linebreak command <br> &ensp; ;
**command** | &rarr; simple_command <br> &ensp; &#124; compound_command redirect_list;
**compound_command** | &rarr; brace_group <br> &ensp; &#124; subshell <br> &ensp; ;
**subsehell** | &rarr; '(' compound_list ')' <br> &ensp; ;
**simple_command** | &rarr; command_name io_redirect <br> &ensp; &#124; ASSIGNMENT command_name io_redirect <br> &ensp;;
**io_redirect** | &rarr; IO_NUMBER io_file <br> &ensp; ;
**io_file** | &rarr; GREATAND filename <br> &ensp; &#124; DGREAT filename <br> &ensp; &#124; LESSGREAT filename <br> &ensp; &#124; LESSAND filename <br> &ensp; ;
**filename** | &rarr; WORD <br> &ensp; ;
**io_here** | &rarr; DLESS here_end <br> &ensp; &#124; DELESS here_end <br> &ensp; ;
**here_end** | &rarr; WORD <br> &ensp; ;
**separator_op** | &rarr; '&' <br> &ensp; &#124; ';' <br> &ensp; ;
**linebreak** | &rarr; '\n' <br> &ensp; ;
**Bang** | &rarr; ';' <br> &ensp; ;
**command_name** | &rarr; WORD <br> &ensp; ;

<p>&nbsp;</p>
## Executer
