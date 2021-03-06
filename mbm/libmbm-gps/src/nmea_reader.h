/* 
 * Copyright (C) Ericsson AB 2009-2014
 * Copyright 2006, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * Author: Carl Nordbeck <carl.nordbeck@ericsson.com>
 *         Torgny Johansson <torgny.johansson@ericsson.com>
 */

#ifndef NMEA_READER_H
#define NMEA_READER_H 1

#include <hardware/gps.h>

#define  NMEA_MAX_SIZE  83

typedef void (*set_pending_callback) (char callback);

typedef struct {
    int pos;
    int overflow;
    int utc_year;
    int utc_mon;
    int utc_day;
    int utc_diff;
    GpsLocation fix;
    GpsSvStatus sv_status;
    int sv_status_changed;
    gps_location_callback callback;
    gps_sv_status_callback sv_status_callback;
    gps_nmea_callback nmea_callback;
    char in[NMEA_MAX_SIZE + 1];
    int update;
} NmeaReader;

typedef struct {
    int isInitialized;
    int loglevel;
} NmeaContext;

/* get the current context */
NmeaContext* get_nmea_context(void);

void nmea_reader_init(NmeaReader * r, int loglevel);

void nmea_reader_set_callbacks(NmeaReader * r, GpsCallbacks * cbs);

void nmea_reader_addc(NmeaReader * r, int c);

void nmea_reader_add(NmeaReader * r, char *nmea);

#endif /* NMEA_READER_H */
