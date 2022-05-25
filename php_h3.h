/* h3 extension for PHP */

#ifndef PHP_H3_H
# define PHP_H3_H

extern zend_module_entry h3_module_entry;
# define phpext_h3_ptr &h3_module_entry

# define PHP_H3_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_H3)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_H3_H */
