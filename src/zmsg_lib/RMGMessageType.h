/*
 * Copyright 2004 Andrew De Ponte
 * 
 * This file is part of zsrep.
 * 
 * zsrep is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 * 
 * zsrep is distributed in the hopes that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with zsrep; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/**
 * @file RMGMessageType.h
 * @brief A specifications file of a message of type RMG.
 * @author Andrew De Ponte
 *
 * A specifications for a class to represent a message that is of type RMG.
 */

#ifndef RMGMESSAGETYPE_H
#define RMGMESSAGETYPE_H

#include "DesktopMessageType.h"

/**
 * @class RMGMessageType
 * @brief A type representing messages of type RMG.
 *
 * The RMGMessageType is a class which represents messages of type RMG. It
 * handles all access to data contained in such messages.
 */
class RMGMessageType : public DesktopMessageType {
 public:
    RMGMessageType(void);
    RMGMessageType(const unsigned char type);
    ~RMGMessageType(void);

    void SetType(const unsigned char type);
 private:
};

#endif
