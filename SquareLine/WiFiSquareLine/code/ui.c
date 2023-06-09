// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.2
// LVGL version: 8.3.4
// Project name: WiFiSquareLine

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_WiFiScreen;
lv_obj_t * ui_ButtonScan;
lv_obj_t * ui_LabelBtnScan;
lv_obj_t * ui_PanelStatus;
lv_obj_t * ui_LabelPanelStatus;
lv_obj_t * ui_RollerNetList;
lv_obj_t * ui_ButtonConnect;
lv_obj_t * ui_LabelBtnConnect;
lv_obj_t * ui_LabelAvailableNet;
lv_obj_t * ui_LabelTitle;
lv_obj_t * ui_PanelPassword;
lv_obj_t * ui_LabelPanelPassword;
lv_obj_t * ui_LabelPassword;
lv_obj_t * ui_PanelSearchNet;
lv_obj_t * ui_LabelPanelSearchNet;
lv_obj_t * ui_ImgPanelSearchNet;
lv_obj_t * ui_PanelConnecting;
lv_obj_t * ui_LabelPanelConnecting;
lv_obj_t * ui_SpinnerConnecting;
lv_obj_t * ui_ImgPanelConnecting;
lv_obj_t * ui_Image2;
lv_obj_t * ui_BtnHome;
lv_obj_t * ui_ImageBtnHome;
lv_obj_t * ui_MainMenu;
lv_obj_t * ui_LabelTitle1;
lv_obj_t * ui_ButtonNetMenu;
lv_obj_t * ui_LabelBtnScan1;
lv_obj_t * ui_ButtonSharedFolderMenu;
lv_obj_t * ui_LabelBtnScan2;
lv_obj_t * ui_PanelStatus1;
lv_obj_t * ui_LabelPanelStatus1;
lv_obj_t * ui_SharedFolderMenu;
lv_obj_t * ui_ShareFolderLabelTitle;
lv_obj_t * ui_PanelStatus2;
lv_obj_t * ui_LabelPanelStatus2;
lv_obj_t * ui_ImageFolder;
lv_obj_t * ui_PanelSharedFolder;
lv_obj_t * ui_LabelSharedFolder;
lv_obj_t * ui_LabelNetwork;
lv_obj_t * ui_ButtonSharedFolderLs;
lv_obj_t * ui_SharedFolderBtnLabel1;
lv_obj_t * ui_LabelNetworkInfo;
lv_obj_t * ui_BtnHome1;
lv_obj_t * ui_ImageBtnHome1;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * home_array[2] = {&ui_img_home2_png, &ui_img_home3_png};
const lv_img_dsc_t * wifi__array[1] = {&ui_img_wifi_1_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////


///////////////////// SCREENS ////////////////////
void ui_WiFiScreen_screen_init(void)
{
    ui_WiFiScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_WiFiScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonScan = lv_btn_create(ui_WiFiScreen);
    lv_obj_set_width(ui_ButtonScan, 222);
    lv_obj_set_height(ui_ButtonScan, 50);
    lv_obj_set_x(ui_ButtonScan, -118);
    lv_obj_set_y(ui_ButtonScan, 86);
    lv_obj_set_align(ui_ButtonScan, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonScan, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonScan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBtnScan = lv_label_create(ui_ButtonScan);
    lv_obj_set_width(ui_LabelBtnScan, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBtnScan, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelBtnScan, -5);
    lv_obj_set_y(ui_LabelBtnScan, 0);
    lv_obj_set_align(ui_LabelBtnScan, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBtnScan, "SCAN");
    lv_obj_set_style_text_color(ui_LabelBtnScan, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBtnScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBtnScan, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStatus = lv_obj_create(ui_WiFiScreen);
    lv_obj_set_width(ui_PanelStatus, 473);
    lv_obj_set_height(ui_PanelStatus, 37);
    lv_obj_set_x(ui_PanelStatus, 2);
    lv_obj_set_y(ui_PanelStatus, 137);
    lv_obj_set_align(ui_PanelStatus, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelPanelStatus = lv_label_create(ui_PanelStatus);
    lv_obj_set_width(ui_LabelPanelStatus, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelStatus, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelStatus, -193);
    lv_obj_set_y(ui_LabelPanelStatus, 1);
    lv_obj_set_align(ui_LabelPanelStatus, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelStatus, "STATUS : ");
    lv_obj_set_style_text_font(ui_LabelPanelStatus, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RollerNetList = lv_roller_create(ui_WiFiScreen);
    lv_roller_set_options(ui_RollerNetList, "SSID List\nOption 1", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_RollerNetList, 217);
    lv_obj_set_height(ui_RollerNetList, 140);
    lv_obj_set_x(ui_RollerNetList, -118);
    lv_obj_set_y(ui_RollerNetList, -16);
    lv_obj_set_align(ui_RollerNetList, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_RollerNetList, lv_color_hex(0x535353), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerNetList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RollerNetList, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_RollerNetList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_RollerNetList, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_set_style_text_color(ui_RollerNetList, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RollerNetList, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_ButtonConnect = lv_btn_create(ui_WiFiScreen);
    lv_obj_set_width(ui_ButtonConnect, 222);
    lv_obj_set_height(ui_ButtonConnect, 50);
    lv_obj_set_x(ui_ButtonConnect, 121);
    lv_obj_set_y(ui_ButtonConnect, 86);
    lv_obj_set_align(ui_ButtonConnect, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonConnect, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConnect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBtnConnect = lv_label_create(ui_ButtonConnect);
    lv_obj_set_width(ui_LabelBtnConnect, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBtnConnect, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelBtnConnect, -5);
    lv_obj_set_y(ui_LabelBtnConnect, 0);
    lv_obj_set_align(ui_LabelBtnConnect, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBtnConnect, "CONNECT");
    lv_obj_set_style_text_color(ui_LabelBtnConnect, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBtnConnect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBtnConnect, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelAvailableNet = lv_label_create(ui_WiFiScreen);
    lv_obj_set_width(ui_LabelAvailableNet, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAvailableNet, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelAvailableNet, -120);
    lv_obj_set_y(ui_LabelAvailableNet, -99);
    lv_obj_set_align(ui_LabelAvailableNet, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAvailableNet, "Available Networks");
    lv_obj_set_style_text_font(ui_LabelAvailableNet, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitle = lv_label_create(ui_WiFiScreen);
    lv_obj_set_width(ui_LabelTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTitle, -6);
    lv_obj_set_y(ui_LabelTitle, -135);
    lv_obj_set_align(ui_LabelTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTitle, "WiFi");
    lv_obj_set_style_text_font(ui_LabelTitle, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPassword = lv_obj_create(ui_WiFiScreen);
    lv_obj_set_width(ui_PanelPassword, 217);
    lv_obj_set_height(ui_PanelPassword, 108);
    lv_obj_set_x(ui_PanelPassword, 121);
    lv_obj_set_y(ui_PanelPassword, -16);
    lv_obj_set_align(ui_PanelPassword, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelPassword, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_PanelPassword, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPanelPassword = lv_label_create(ui_PanelPassword);
    lv_obj_set_width(ui_LabelPanelPassword, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelPassword, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelPassword, -6);
    lv_obj_set_y(ui_LabelPanelPassword, -1);
    lv_obj_set_align(ui_LabelPanelPassword, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelPassword, "|");

    ui_LabelPassword = lv_label_create(ui_WiFiScreen);
    lv_obj_set_width(ui_LabelPassword, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPassword, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPassword, 121);
    lv_obj_set_y(ui_LabelPassword, -99);
    lv_obj_set_align(ui_LabelPassword, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPassword, "Password :");
    lv_obj_set_style_text_font(ui_LabelPassword, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSearchNet = lv_obj_create(ui_WiFiScreen);
    lv_obj_set_width(ui_PanelSearchNet, 217);
    lv_obj_set_height(ui_PanelSearchNet, 106);
    lv_obj_set_x(ui_PanelSearchNet, -118);
    lv_obj_set_y(ui_PanelSearchNet, -21);
    lv_obj_set_align(ui_PanelSearchNet, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelSearchNet, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelSearchNet, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelPanelSearchNet = lv_label_create(ui_PanelSearchNet);
    lv_obj_set_width(ui_LabelPanelSearchNet, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelSearchNet, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelSearchNet, -2);
    lv_obj_set_y(ui_LabelPanelSearchNet, 35);
    lv_obj_set_align(ui_LabelPanelSearchNet, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelSearchNet, "Searching ...");
    lv_obj_set_style_text_font(ui_LabelPanelSearchNet, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgPanelSearchNet = lv_img_create(ui_PanelSearchNet);
    lv_img_set_src(ui_ImgPanelSearchNet, &ui_img_search_wifi_png);
    lv_obj_set_width(ui_ImgPanelSearchNet, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_ImgPanelSearchNet, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_x(ui_ImgPanelSearchNet, -6);
    lv_obj_set_y(ui_ImgPanelSearchNet, -12);
    lv_obj_set_align(ui_ImgPanelSearchNet, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgPanelSearchNet, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgPanelSearchNet, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelConnecting = lv_obj_create(ui_WiFiScreen);
    lv_obj_set_width(ui_PanelConnecting, 217);
    lv_obj_set_height(ui_PanelConnecting, 108);
    lv_obj_set_x(ui_PanelConnecting, 121);
    lv_obj_set_y(ui_PanelConnecting, -21);
    lv_obj_set_align(ui_PanelConnecting, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelConnecting, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelConnecting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelPanelConnecting = lv_label_create(ui_PanelConnecting);
    lv_obj_set_width(ui_LabelPanelConnecting, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelConnecting, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelConnecting, -2);
    lv_obj_set_y(ui_LabelPanelConnecting, 35);
    lv_obj_set_align(ui_LabelPanelConnecting, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelConnecting, "Connecting ...");
    lv_obj_set_style_text_font(ui_LabelPanelConnecting, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SpinnerConnecting = lv_spinner_create(ui_PanelConnecting, 1000, 90);
    lv_obj_set_width(ui_SpinnerConnecting, 80);
    lv_obj_set_height(ui_SpinnerConnecting, 59);
    lv_obj_set_x(ui_SpinnerConnecting, 6);
    lv_obj_set_y(ui_SpinnerConnecting, -10);
    lv_obj_set_align(ui_SpinnerConnecting, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SpinnerConnecting, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_ImgPanelConnecting = lv_img_create(ui_PanelConnecting);
    lv_img_set_src(ui_ImgPanelConnecting, &ui_img_1656806725);
    lv_obj_set_width(ui_ImgPanelConnecting, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_ImgPanelConnecting, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_x(ui_ImgPanelConnecting, -3);
    lv_obj_set_y(ui_ImgPanelConnecting, -9);
    lv_obj_set_align(ui_ImgPanelConnecting, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgPanelConnecting, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgPanelConnecting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image2 = lv_img_create(ui_PanelConnecting);
    lv_img_set_src(ui_Image2, &ui_img_wifi_1_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_x(ui_Image2, -4);
    lv_obj_set_y(ui_Image2, -7);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BtnHome = lv_btn_create(ui_WiFiScreen);
    lv_obj_set_width(ui_BtnHome, 50);
    lv_obj_set_height(ui_BtnHome, 35);
    lv_obj_set_x(ui_BtnHome, -208);
    lv_obj_set_y(ui_BtnHome, -138);
    lv_obj_set_align(ui_BtnHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnHome, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageBtnHome = lv_img_create(ui_BtnHome);
    lv_img_set_src(ui_ImageBtnHome, &ui_img_home3_png);
    lv_obj_set_width(ui_ImageBtnHome, LV_SIZE_CONTENT);   /// 25
    lv_obj_set_height(ui_ImageBtnHome, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_ImageBtnHome, -1);
    lv_obj_set_y(ui_ImageBtnHome, -1);
    lv_obj_set_align(ui_ImageBtnHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageBtnHome, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBtnHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_MainMenu_screen_init(void)
{
    ui_MainMenu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainMenu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTitle1 = lv_label_create(ui_MainMenu);
    lv_obj_set_width(ui_LabelTitle1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTitle1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTitle1, -6);
    lv_obj_set_y(ui_LabelTitle1, -135);
    lv_obj_set_align(ui_LabelTitle1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTitle1, "Main Menu");
    lv_obj_set_style_text_font(ui_LabelTitle1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonNetMenu = lv_btn_create(ui_MainMenu);
    lv_obj_set_width(ui_ButtonNetMenu, 222);
    lv_obj_set_height(ui_ButtonNetMenu, 50);
    lv_obj_set_x(ui_ButtonNetMenu, 0);
    lv_obj_set_y(ui_ButtonNetMenu, -51);
    lv_obj_set_align(ui_ButtonNetMenu, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonNetMenu, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonNetMenu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBtnScan1 = lv_label_create(ui_ButtonNetMenu);
    lv_obj_set_width(ui_LabelBtnScan1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBtnScan1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelBtnScan1, -5);
    lv_obj_set_y(ui_LabelBtnScan1, 0);
    lv_obj_set_align(ui_LabelBtnScan1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBtnScan1, "WiFi Configuration");
    lv_obj_set_style_text_color(ui_LabelBtnScan1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBtnScan1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBtnScan1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSharedFolderMenu = lv_btn_create(ui_MainMenu);
    lv_obj_set_width(ui_ButtonSharedFolderMenu, 222);
    lv_obj_set_height(ui_ButtonSharedFolderMenu, 50);
    lv_obj_set_x(ui_ButtonSharedFolderMenu, 0);
    lv_obj_set_y(ui_ButtonSharedFolderMenu, 25);
    lv_obj_set_align(ui_ButtonSharedFolderMenu, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonSharedFolderMenu, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSharedFolderMenu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBtnScan2 = lv_label_create(ui_ButtonSharedFolderMenu);
    lv_obj_set_width(ui_LabelBtnScan2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBtnScan2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelBtnScan2, -5);
    lv_obj_set_y(ui_LabelBtnScan2, 0);
    lv_obj_set_align(ui_LabelBtnScan2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBtnScan2, "Shared Folder");
    lv_obj_set_style_text_color(ui_LabelBtnScan2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBtnScan2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBtnScan2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStatus1 = lv_obj_create(ui_MainMenu);
    lv_obj_set_width(ui_PanelStatus1, 473);
    lv_obj_set_height(ui_PanelStatus1, 37);
    lv_obj_set_x(ui_PanelStatus1, 2);
    lv_obj_set_y(ui_PanelStatus1, 137);
    lv_obj_set_align(ui_PanelStatus1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelStatus1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelPanelStatus1 = lv_label_create(ui_PanelStatus1);
    lv_obj_set_width(ui_LabelPanelStatus1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelStatus1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelStatus1, -193);
    lv_obj_set_y(ui_LabelPanelStatus1, 1);
    lv_obj_set_align(ui_LabelPanelStatus1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelStatus1, "STATUS : ");
    lv_obj_set_style_text_font(ui_LabelPanelStatus1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_SharedFolderMenu_screen_init(void)
{
    ui_SharedFolderMenu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SharedFolderMenu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ShareFolderLabelTitle = lv_label_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_ShareFolderLabelTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ShareFolderLabelTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ShareFolderLabelTitle, -6);
    lv_obj_set_y(ui_ShareFolderLabelTitle, -135);
    lv_obj_set_align(ui_ShareFolderLabelTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ShareFolderLabelTitle, "Shared Folder");
    lv_obj_set_style_text_font(ui_ShareFolderLabelTitle, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStatus2 = lv_obj_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_PanelStatus2, 473);
    lv_obj_set_height(ui_PanelStatus2, 37);
    lv_obj_set_x(ui_PanelStatus2, 2);
    lv_obj_set_y(ui_PanelStatus2, 137);
    lv_obj_set_align(ui_PanelStatus2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelStatus2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelPanelStatus2 = lv_label_create(ui_PanelStatus2);
    lv_obj_set_width(ui_LabelPanelStatus2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelStatus2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelStatus2, -193);
    lv_obj_set_y(ui_LabelPanelStatus2, 1);
    lv_obj_set_align(ui_LabelPanelStatus2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelStatus2, "STATUS : ");
    lv_obj_set_style_text_font(ui_LabelPanelStatus2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageFolder = lv_img_create(ui_SharedFolderMenu);
    lv_img_set_src(ui_ImageFolder, &ui_img_network_png);
    lv_obj_set_width(ui_ImageFolder, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_ImageFolder, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_x(ui_ImageFolder, 197);
    lv_obj_set_y(ui_ImageFolder, -121);
    lv_obj_set_align(ui_ImageFolder, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageFolder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFolder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelSharedFolder = lv_obj_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_PanelSharedFolder, 352);
    lv_obj_set_height(ui_PanelSharedFolder, 163);
    lv_obj_set_x(ui_PanelSharedFolder, 53);
    lv_obj_set_y(ui_PanelSharedFolder, -4);
    lv_obj_set_align(ui_PanelSharedFolder, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelSharedFolder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelSharedFolder = lv_label_create(ui_PanelSharedFolder);
    lv_obj_set_width(ui_LabelSharedFolder, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSharedFolder, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSharedFolder, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSharedFolder, "");

    ui_LabelNetwork = lv_label_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_LabelNetwork, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelNetwork, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelNetwork, -194);
    lv_obj_set_y(ui_LabelNetwork, 101);
    lv_obj_set_align(ui_LabelNetwork, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelNetwork, "Network:");
    lv_obj_set_style_text_font(ui_LabelNetwork, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSharedFolderLs = lv_btn_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_ButtonSharedFolderLs, 100);
    lv_obj_set_height(ui_ButtonSharedFolderLs, 34);
    lv_obj_set_x(ui_ButtonSharedFolderLs, -183);
    lv_obj_set_y(ui_ButtonSharedFolderLs, -65);
    lv_obj_set_align(ui_ButtonSharedFolderLs, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonSharedFolderLs, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSharedFolderLs, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SharedFolderBtnLabel1 = lv_label_create(ui_ButtonSharedFolderLs);
    lv_obj_set_width(ui_SharedFolderBtnLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SharedFolderBtnLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SharedFolderBtnLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SharedFolderBtnLabel1, "LS");
    lv_obj_set_style_text_color(ui_SharedFolderBtnLabel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SharedFolderBtnLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelNetworkInfo = lv_label_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_LabelNetworkInfo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelNetworkInfo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelNetworkInfo, 44);
    lv_obj_set_y(ui_LabelNetworkInfo, 101);
    lv_obj_set_align(ui_LabelNetworkInfo, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelNetworkInfo, "smb://User49@192.168.11.2/ShareNetwork");

    ui_BtnHome1 = lv_btn_create(ui_SharedFolderMenu);
    lv_obj_set_width(ui_BtnHome1, 50);
    lv_obj_set_height(ui_BtnHome1, 35);
    lv_obj_set_x(ui_BtnHome1, -208);
    lv_obj_set_y(ui_BtnHome1, -138);
    lv_obj_set_align(ui_BtnHome1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnHome1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnHome1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageBtnHome1 = lv_img_create(ui_BtnHome1);
    lv_img_set_src(ui_ImageBtnHome1, &ui_img_home3_png);
    lv_obj_set_width(ui_ImageBtnHome1, LV_SIZE_CONTENT);   /// 25
    lv_obj_set_height(ui_ImageBtnHome1, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_ImageBtnHome1, -1);
    lv_obj_set_y(ui_ImageBtnHome1, -1);
    lv_obj_set_align(ui_ImageBtnHome1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageBtnHome1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBtnHome1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_WiFiScreen_screen_init();
    ui_MainMenu_screen_init();
    ui_SharedFolderMenu_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_WiFiScreen);
}
