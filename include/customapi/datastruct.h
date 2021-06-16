#ifndef CUSTOM_DATASTRUCT_H_
#define CUSTOM_DATASTRUCT_H_

/// 升水。期货价格高于现货价格。
#define IC_STATUS_CONTANGO '0'
/// 贴水。期货价格低于现货价格。
#define IC_STATUS_BACKWARDATION '1'

// 多路行情源
#define MD_SOURCE_CTP '0'
#define MD_SOURCE_TF '1'


// struct MDQuote {
// 	char exchange_id[32];
// 	char instrument_id[32];
//     char source;

// 	double pre_cls_price;
// 	double last_price;
//     uint32_t volume;
//     uint64_t IOPV;

// 	double ask_px_1;
//     double ask_vol_1;
//     double ask_px_2;
//     double ask_vol_2; 
//     double ask_px_3;
//     double ask_vol_3;
//     double ask_px_4;
//     double ask_vol_4;
//     double ask_px_5;
//     double ask_vol_5;

//     double bid_px_1;
//     double bid_vol_1;
//     double bid_px_2;
//     double bid_vol_2;
//     double bid_px_3;
//     double bid_vol_3;
//     double bid_px_4;
//     double bid_vol_4;
//     double bid_px_5;
//     double bid_vol_5;

// 	uint32_t ex_time;

// 	MDQuote() { memset(this, 0, sizeof(MDQuote)); }
// };

// struct PDQuote {
// 	MDQuote etf_quote;
// 	MDQuote ic_quote;

// 	char ic_status;
//     double value_difference;
// 	double price_difference;

// 	double etf_insert_volume;

// 	PDQuote() { memset(this, 0, sizeof(PDQuote)); }
// };


// struct InstrumentQuote {
//     char exchange_id[32];
//     char instrument_id[32];

//     double ask_px_1;
//     double ask_vol_1;
//     double ask_px_2;
//     double ask_vol_2;
//     double ask_px_3;
//     double ask_vol_3;
//     double ask_px_4;
//     double ask_vol_4;
//     double ask_px_5;
//     double ask_vol_5;

//     double bid_px_1;
//     double bid_vol_1;
//     double bid_px_2;
//     double bid_vol_2;
//     double bid_px_3;
//     double bid_vol_3;
//     double bid_px_4;
//     double bid_vol_4;
//     double bid_px_5;
//     double bid_vol_5;

//     uint32_t volume;

//     double last_price;
// };


#endif
