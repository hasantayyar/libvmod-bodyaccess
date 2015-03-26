#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "cache/cache.h"

#include "vrt.h"
#include "vcl.h"
#include "vsha256.h"
#include "vcc_if.h"
struct vmod {
	ssize_t len;
	void *priv;
};
int concat_req_body(struct req *req, void *priv, void *ptr, size_t len);
void HSH_AddBytes(const struct req *req, const void *buf, size_t len);
ssize_t http1_iter_req_body(struct req *req, enum req_body_state_e bs,
    void *buf, ssize_t len);
struct vmod vmod_blob_req_body(VRT_CTX, struct vmod vmod);
int VRB_Cache(struct req *req, ssize_t maxsize);