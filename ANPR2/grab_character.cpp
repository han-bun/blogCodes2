#include "grab_character.hpp"

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <boost/filesystem.hpp>

#include <iomanip>
#include <iostream>
#include <sstream>

grab_character::grab_character() :
    chars_folder_(boost::filesystem::current_path().string() +
                  "/chars_folder")
{
    for(char i = '0'; i <= '9'; ++i){
        char_count_.insert({std::string(1,i), 0});
    }
    for(char i = 'a'; i <= 'z'; ++i){
        char_count_.insert({std::string(1,i), 0});
    }
    for(char i = 'A'; i <= 'Z'; ++i){
        char_count_.insert({std::string(1,i), 0});
    }
    char_count_.insert({"*", 0});
}

void grab_character::
grab_chars(cv::Mat const &plate,
           contours_type const &contours)
{
    if(!boost::filesystem::exists(chars_folder_)){
        boost::filesystem::create_directory(chars_folder_);
    }

    cv::Mat contour_img;
    for(int i = 0; i != contours.size(); ++i){
        try{
            auto const rect = cv::boundingRect(contours[i]);
            cv::imshow("char candidate", plate(rect));

            plate.copyTo(contour_img);
            cv::drawContours(contour_img, contours, i,
            {0,255,0}, 2);
            cv::imshow("contour", contour_img);

            int const key = cv::waitKey();
            if(key == '-'){
                continue;
            }else if(key == 'q'){
                break;
            }else{
                std::string const map_key(1, char(key));
                std::string folder;
                std::string file_symbol;
                if(map_key != "*"){
                    folder = chars_folder_ + "/" + map_key;
                    file_symbol = map_key;
                }else{
                    folder = chars_folder_ + "/negative";
                    file_symbol = "negative";
                }
                if(!boost::filesystem::exists(folder)){
                    boost::filesystem::create_directory(folder);
                }
                std::ostringstream ostream;
                ostream<<folder<<"/"<<file_symbol<<"_"<<std::setfill('0')
                      <<std::setw(4)<<char_count_[map_key]++;
                cv::imwrite(ostream.str() + ".png",
                            plate(rect));
                cv::destroyAllWindows();
            }
        }catch(std::exception const &ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
}

void grab_character::set_chars_folder(const std::string &value)
{
    chars_folder_ = value;
}
