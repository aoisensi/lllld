#ifndef _APP_H_

#define SAFE_DELETE(x) { delete x; x=NULL; }
#define SAFE_DELETE_ARRAY(x) { delete[] x; x=NULL }

#endif
