clang -dynamiclib\
    -std=gnu99\
    apue_err.c\
    apue_log.c\
    -current_version 1.0\
    -compatibility_version 1.0\
    -o libapue_core.A.dylib
