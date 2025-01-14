#ifndef __DISPLAY_UTILS_H__
#define __DISPLAY_UTILS_H__

#include <vector>
#include <time.h>
#include "api_response.h"

enum alert_category {
  NOT_FOUND = -1,
  SMOG,
  SMOKE,
  FOG,
  METEOR,
  NUCLEAR,
  BIOHAZARD,
  EARTHQUAKE,
  TSUNAMI,
  FIRE,
  HEAT,
  WINTER,
  LIGHTNING,
  SANDSTORM,
  FLOOD,
  VOLCANO,
  AIR_QUALITY,
  TORNADO,
  SMALL_CRAFT_ADVISORY,
  GALE_WARNING,
  STORM_WARNING,
  HURRICANE_WARNING,
  HURRICANE,
  DUST,
  STRONG_WIND
};

int calcBatPercent(double v);
const uint8_t *getBatBitmap24(int batPercent);
void getDateStr(String &s, tm *timeInfo);
void getRefreshTimeStr(String &s, bool timeSuccess, tm *timeInfo);
void toTitleCase(String &text);
void truncateExtraAlertInfo(String &text);
void filterAlerts(std::vector<owm_alerts_t> &resp, int *ignore_list);
const char *getUVIdesc(unsigned int uvi);
float getAvgConc(float pollutant[], int hours);
int getAQI(owm_resp_air_pollution_t &p);
const char *getAQIdesc(int aqi);
const char *getWiFidesc(int rssi);
const uint8_t *getWiFiBitmap16(int rssi);
const uint8_t *getForecastBitmap64(owm_daily_t &daily);
const uint8_t *getCurrentConditionsBitmap196(owm_current_t &current, 
                                             owm_daily_t   &today);
const uint8_t *getAlertBitmap32(owm_alerts_t &alert);
const uint8_t *getAlertBitmap48(owm_alerts_t &alert);
enum alert_category getAlertCategory(owm_alerts_t &alert);
const uint8_t *getWindBitmap24(int windDeg);
const char *getHttpResponsePhrase(int code);
const char *getWifiStatusPhrase(wl_status_t status);

#endif
