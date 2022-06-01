/* h3 extension for PHP */

#ifndef PHP_H3_H
#define PHP_H3_H

extern zend_module_entry h3_module_entry;
#define phpext_h3_ptr &h3_module_entry

#define PHP_H3_VERSION "1.0.0-alpha3"

#if defined(ZTS) && defined(COMPILE_DL_H3)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

// clang-format off
ZEND_BEGIN_MODULE_GLOBALS(h3)
    zend_bool validate_res;
    zend_bool validate_index;
ZEND_END_MODULE_GLOBALS(h3);
// clang-format on

ZEND_EXTERN_MODULE_GLOBALS(h3)

#define H3_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(h3, v)

#endif /* PHP_H3_H */
