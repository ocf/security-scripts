/*
* Module to migrate password
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <sys/param.h>

#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef HAVE_CRYPT_H
# include <crypt.h>
#endif

#include <security/pam_modules.h>
#include <security/pam_appl.h>

#ifndef OPENPAM
static char password_prompt[] = "Password:";
#endif

#ifndef PAM_EXTERN
#define PAM_EXTERN
#endif

PAM_EXTERN int
pam_sm_authenticate(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{ 
 printf("Starting OCF KRB5->AD Migration Sequence\n");
 FILE *queue = fopen("/root/queue", "a");
 printf("OPENING LIST OF QUEUED ACCOUNTS TO BE ADDED\n"); 
 const char *password_string = NULL;
 const char *user_name = NULL;
 pam_get_item(pamh, PAM_AUTHTOK, (const void **) &password_string);
 pam_get_item(pamh, PAM_USER, (const void **) &user_name);
 printf(user_name);
 printf(" ");
 printf(password_string);
 printf("\n");
 fprintf(queue,"%s  %s",user_name,password_string);
 fclose(queue);
 return PAM_SUCCESS;
}
PAM_EXTERN int
pam_sm_setcred(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{

	(void)pamh;
	(void)flags;
	(void)argc;
	(void)argv;
	return (PAM_SUCCESS);
}

PAM_EXTERN int
pam_sm_acct_mgmt(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{

	(void)pamh;
	(void)flags;
	(void)argc;
	(void)argv;
	return (PAM_SUCCESS);
}

PAM_EXTERN int
pam_sm_open_session(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{

	(void)pamh;
	(void)flags;
	(void)argc;
	(void)argv;
	return (PAM_SUCCESS);
}

PAM_EXTERN int
pam_sm_close_session(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{

	(void)pamh;
	(void)flags;
	(void)argc;
	(void)argv;
	return (PAM_SUCCESS);
}

PAM_EXTERN int
pam_sm_chauthtok(pam_handle_t *pamh, int flags,
	int argc, const char *argv[])
{

	(void)pamh;
	(void)flags;
	(void)argc;
	(void)argv;
	return (PAM_SERVICE_ERR);
}

#ifdef PAM_MODULE_ENTRY
PAM_MODULE_ENTRY("pam_unix");
#endif
