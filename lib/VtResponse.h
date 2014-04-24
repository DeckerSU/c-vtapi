/*
Copyright 2014 VirusTotal S.L. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef VT_RESPONSE_H
#define VT_RESPONSE_H 1


#ifdef  __cplusplus
extern "C" {
#endif

/**
* @ingroup VtObject
* @defgroup VtResponse VtResponse object.  All API responses stored here.
* @{
*/


/// Flag to include debug info in JSON if necessary
#define VT_JSON_FLAG_DEBUG   1 << 0

/// Indent JSON
#define VT_JSON_FLAG_INDENT  1 << 1

struct VtResponse;

struct VtResponse* VtResponse_new(void);


/**
 * @brief Get a reference counter.
 * 
 * @param VtResponse Response object
 * @return void
 */
void VtResponse_get(struct VtResponse *VtResponse);


/** put a reference counter */
void VtResponse_put(struct VtResponse **VtResponse);

char * VtResponse_getVerboseMsg(struct VtResponse *response, char *buf, int buf_siz);

int VtResponse_getResponseCode(struct VtResponse *response, int *response_code);

char * VtResponse_toJSONstr(struct VtResponse *response, int flags);

int VtResponse_fromJSON(struct VtResponse *response, json_t *json);

int VtResponse_fromJSONstr(struct VtResponse *response, const char *json_str);

int VtResponse_getIntValue(struct VtResponse *response, const char *key, int *value);

char *VtResponse_getString(struct VtResponse *response, const char *key);


/**
 * @brief Get raw jansson response object
 * 
 * @param response borrowed json_t pointer.
 * @return json_t*
 */
json_t * VtResponse_getJanssonObj(struct VtResponse *response);

/** @} */


#ifdef  __cplusplus
}
#endif /*cplusplus*/

#endif
