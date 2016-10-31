/*
 * Library security_descriptor type testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcstring.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_memory.h"
#include "fwnt_test_unused.h"

uint8_t fwnt_test_security_descriptor_byte_stream[ 116 ] = {
	0x01, 0x00, 0x04, 0x80, 0x48, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x14, 0x00, 0x00, 0x00, 0x02, 0x00, 0x34, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00,
	0x9f, 0x01, 0x12, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x12, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x00, 0x9f, 0x01, 0x12, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	0x15, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xc8, 0x68, 0xdd, 0xe8, 0xe4, 0x1c, 0x8a, 0xa7, 0x32, 0x3f,
	0xeb, 0x03, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x00, 0x00, 0x00,
	0x20, 0x02, 0x00, 0x00 };

/* Tests the libfwnt_security_descriptor_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_initialize(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	int result                                         = 0;

	/* Test libfwnt_security_descriptor_initialize
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_initialize(
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	security_descriptor = (libfwnt_security_descriptor_t *) 0x12345678UL;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	security_descriptor = NULL;

#if defined( HAVE_FWNT_TEST_MEMORY )

	/* Test libfwnt_security_descriptor_initialize with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;

		if( security_descriptor != NULL )
		{
			libfwnt_security_descriptor_free(
			 &security_descriptor,
			 NULL );
		}
	}
	else
	{
		FWNT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWNT_TEST_ASSERT_IS_NULL(
		 "security_descriptor",
		 security_descriptor );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwnt_security_descriptor_initialize with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;

		if( security_descriptor != NULL )
		{
			libfwnt_security_descriptor_free(
			 &security_descriptor,
			 NULL );
		}
	}
	else
	{
		FWNT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWNT_TEST_ASSERT_IS_NULL(
		 "security_descriptor",
		 security_descriptor );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWNT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_free(
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to copy security descriptor from byte stream
	 */
	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          NULL,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          NULL,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          0,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          20,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          (uint8_t) 'X',
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_get_owner function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_get_owner(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve owner
	 */
	result = libfwnt_security_descriptor_get_owner(
	          security_descriptor,
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_get_owner(
	          NULL,
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_get_owner(
	          security_descriptor,
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_get_group function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_get_group(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve group
	 */
	result = libfwnt_security_descriptor_get_group(
	          security_descriptor,
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_identifier",
         security_identifier );

	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_get_group(
	          NULL,
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_get_group(
	          security_descriptor,
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_get_discretionary_acl function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_get_discretionary_acl(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_access_control_list_t *access_control_list = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve discretionary ACL
	 */
	result = libfwnt_security_descriptor_get_discretionary_acl(
	          security_descriptor,
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

        FWNT_TEST_ASSERT_IS_NULL(
         "access_control_list",
         access_control_list );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_get_discretionary_acl(
	          NULL,
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_get_discretionary_acl(
	          security_descriptor,
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_get_system_acl function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_get_system_acl(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_access_control_list_t *access_control_list = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          security_descriptor,
	          fwnt_test_security_descriptor_byte_stream,
	          116,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve system ACL
	 */
	result = libfwnt_security_descriptor_get_system_acl(
	          security_descriptor,
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "access_control_list",
         access_control_list );

	result = libfwnt_access_control_list_free(
	          &access_control_list,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_get_system_acl(
	          NULL,
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfwnt_security_descriptor_get_system_acl(
	          security_descriptor,
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_initialize",
	 fwnt_test_security_descriptor_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_free",
	 fwnt_test_security_descriptor_free );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_copy_from_byte_stream",
	 fwnt_test_security_descriptor_copy_from_byte_stream );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_get_owner",
	 fwnt_test_security_descriptor_get_owner );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_get_group",
	 fwnt_test_security_descriptor_get_group );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_get_discretionary_acl",
	 fwnt_test_security_descriptor_get_discretionary_acl );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_get_system_acl",
	 fwnt_test_security_descriptor_get_system_acl );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
