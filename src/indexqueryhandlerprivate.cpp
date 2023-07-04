// Copyright (c) 2023 Manuel Schneider

#include "indexqueryhandlerprivate.h"
using namespace std;
using namespace albert;

IndexQueryHandlerPrivate::IndexQueryHandlerPrivate(IndexQueryHandler *q_) : q(q_) {}

IndexQueryHandlerPrivate::~IndexQueryHandlerPrivate() = default;

void IndexQueryHandlerPrivate::setIndex(unique_ptr<Index> &&index)
{
    index_ = ::move(index);
    if(index_)
        q->updateIndexItems();
}

void IndexQueryHandlerPrivate::setIndexItems(vector<IndexItem> &&index_items)
{
    if (index_)
        index_->setItems(::move(index_items));
}

vector<RankItem>
IndexQueryHandlerPrivate::handleGlobalQuery(const GlobalQueryHandler::GlobalQuery *query) const
{
    if (index_)
        return index_->search(query->string(), query->isValid());
    else
        return {};
}