//
// Created by vladvoicux64 on 3/23/24.
//

#include <utility>
#include "Installation.h"


Installation::Installation(const tm &installation_date, Package master, const std::vector<Package> &dependencies)
        : master_(std::move(master)),
          dependencies_(dependencies), installation_date_(installation_date)
{}

std::ostream &operator<<(std::ostream &ostream, const Installation &installation)
{
    char date_buffer[128];
    strftime(date_buffer, 128, "%c\n", &installation.installation_date_);

    ostream << "Package installed:\n\n" << installation.master_;
    if (!installation.dependencies_.empty()) {
        ostream << "\n\nDependencies installed:\n\n";
        for (const auto &dependency: installation.dependencies_) {
            ostream << dependency << std::endl;
        }
    } else {
        ostream << "\n\nThis package did not install any dependencies.";
    }
    return ostream;
}
